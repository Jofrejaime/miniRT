
# 🚀 miniRT — Roadmap de Implementação

> *Este projeto é um Ray Tracer em C desenvolvido do zero utilizando a MiniLibX como parte do currículo da 42.*

---

## 📌 Visão Geral do Projeto
- **Grupo:** 2 Desenvolvedores
- **Linguagem:** C (conforme a 42 Norm v4) + MiniLibX + libm
- **Formato de Cena:** `.rt`
- **Fases:** 9 Fases Sequenciais (Obrigatórias + Bónus)

---

## 📊 Progresso Geral

- [ ] **Fase 0:** Setup do repositório e esqueleto do projeto
- [ ] **Fase 1:** Biblioteca de vetores 3D
- [ ] **Fase 2:** Parser do ficheiro de cena `.rt`
- [ ] **Fase 3:** Janela MiniLibX e loop de eventos
- [ ] **Fase 4:** Geração de raios e câmara
- [ ] **Fase 5:** Motor de interseções
- [ ] **Fase 6:** Modelo de iluminação
- [ ] **Fase 7:** Integração, testes e validação final
- [ ] **Fase 8:** Bónus (Opcional)

---

## 🛠️ Detalhamento das Fases

---

### 0️⃣ Fase 0 · Fundação — Setup do Repositório e Esqueleto
> **Resumo:** Git, Makefile, Norm, libft, parsing de argumentos.

#### 💡 Tutorial de Apoio
Antes de tocar em ray tracing, o grupo precisa de uma base que compile e cumpras a Norm desde o primeiro commit — corrigir a Norm no fim é sempre mais doloroso. Definam já a estrutura de pastas (`src/`, `includes/`, `libft/`, `minilibx/`), o `Makefile` com as regras obrigatórias (`$(NAME)`, `all`, `clean`, `fclean`, `re`, `bonus`) e um `main.c` que apenas valida os argumentos (deve receber exatamente um ficheiro `.rt`).

#### 📋 Divisão de Tarefas
##### Dev A — Infraestrutura
- [ ] Criar repositório Git e estrutura de pastas (`src/`, `includes/`, `libft/`)
- [ ] Escrever `Makefile` com as 5 regras obrigatórias e flags `-Wall -Wextra -Werror -lm`
- [ ] Integrar a `libft` e o seu próprio `Makefile`
- [ ] Configurar CI simples ou script local de verificação da Norm

##### Dev B — Esqueleto do Programa
- [ ] Criar `main.c` com validação de `argc`/`argv` e extensão `.rt`
- [ ] Definir header principal (`minirt.h`) com structs iniciais (`t_scene`, `t_data`)
- [ ] Criar sistema de erro uniforme: imprime `Error\n` + mensagem e sai limpo
- [ ] Escrever `README.md` inicial com a linha itálica obrigatória e secção Description

#### 💻 Exemplo: Makefile Mínimo
```makefile
NAME = miniRT
CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lm -Lminilibx-linux -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OBJS) libft/libft.a
	$(CC) $(OBJS) libft/libft.a $(LDFLAGS) -o $(NAME)

bonus: CFLAGS += -DBONUS=1
bonus: all


#### 📚 Referências

* **42 Norm v4:** Referência oficial das regras de estilo obrigatórias.
* **GNU Make Manual:** Regras phony e organização de objetos.

---

### 1️⃣ Fase 1 · Fundação Matemática — Biblioteca de Vetores 3D

> **Resumo:** `t_vec3`, produto escalar/vetorial, normalização, rotações.

#### 💡 Tutorial de Apoio

Todo o ray tracer assenta em operações vetoriais: um raio é **origem + t·direção**, uma interseção usa produto escalar e vetorial, uma normal precisa de estar normalizada. Construam esta biblioteca isolada e testem-na sozinha antes de a ligar ao resto — poupa horas de debug mais tarde, porque um erro de sinal aqui propaga-se para toda a imagem.

#### 📋 Divisão de Tarefas

##### Dev A — Operações Vetoriais

* [ ] Implementar struct `t_vec3` e operações: `add`, `sub`, `scale`, `dot`, `cross`
* [ ] Implementar `normalize()` e `length()`
* [ ] Escrever testes unitários simples

##### Dev B — Transformações

* [ ] Implementar rotação de vetores para eixo arbitrário
* [ ] Implementar conversão entre coordenadas locais do objeto e coordenadas do mundo
* [ ] Validar vetores de orientação lidos do `.rt` (intervalo `[-1,1]`)

#### 💻 Exemplo: `vec3.c`

```c
double vec3_dot(t_vec3 a, t_vec3 b)
{
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec3 vec3_normalize(t_vec3 v)
{
    double len;

    len = sqrt(vec3_dot(v, v));
    if (len == 0)
        return (v);
    return ((t_vec3){v.x / len, v.y / len, v.z / len});
}

```

#### 📚 Referências

* **Ray Tracing in One Weekend (Peter Shirley):** Capítulo de `vec3`.
* **Scratchapixel — Geometry:** Álgebra vetorial aplicada a gráficos 3D.
* **3Blue1Brown — Essence of Linear Algebra:** Intuição visual para produto vetorial e rotações.

---

### 2️⃣ Fase 2 · Parsing — Parser do Ficheiro de Cena `.rt`

> **Resumo:** Ler `A`, `C`, `L`, `sp`, `pl`, `cy` e validar cada campo.

#### 💡 Tutorial de Apoio

O subject define uma sintaxe estrita: identificador + campos separados por espaços, elementos separados por quebras de linha, ordem livre entre tipos, mas **A e C só podem aparecer uma vez**. Tratem o parser como uma máquina de estados simples: uma função por tipo de elemento, cada uma validando os seus próprios intervalos (cor 0-255, luz 0.0-1.0, vetores normalizados). Qualquer erro deve terminar o programa de forma limpa com `Error\n` — nunca crash.

#### 📋 Divisão de Tarefas

##### Dev A — Leitura e Tokenização

* [ ] Ler o ficheiro linha a linha (`get_next_line`)
* [ ] Tokenizar cada linha e identificar o elemento (`A`, `C`, `L`, `sp`, `pl`, `cy`)
* [ ] Separar por espaços e vírgulas, tolerando múltiplos espaços

##### Dev B — Validação e Preenchimento

* [ ] Implementar `parse_ambient`, `parse_camera`, `parse_light`
* [ ] Implementar `parse_sphere`, `parse_plane`, `parse_cylinder`
* [ ] Validar intervalos de cada campo e impedir duplicação de `A` e `C`
* [ ] Garantir libertação de toda a memória em caso de erro (zero leaks)

#### 💻 Exemplo de Cena Mínima (`.rt`)

```text
A 0.2                     255,255,255
C -50,0,20   0,0,1         70
L -40,0,30                 0.7    255,255,255

pl 0,0,0     0,1.0,0                       255,0,225
sp 0,0,20                  20               255,0,0
cy 50.0,0.0,20.6 0,0,1.0   14.2 21.42      10,0,255

```

#### 📚 Referências

* **man 3 strtod / man 3 getline:** Funções de parsing em C.
* **42 subject — Chapter IV:** Tabela exata de campos e limites.

---

### 3️⃣ Fase 3 · Janela — MiniLibX e Loop de Eventos

> **Resumo:** Abrir janela, buffer de imagem, ESC e fecho limpo.

#### 💡 Tutorial de Apoio

A MiniLibX dá uma janela e um buffer de píxeis; o resto é convosco. Usem `mlx_new_image` e escrevam diretamente no buffer com `mlx_get_data_addr` em vez de `mlx_pixel_put` pixel a pixel — é ordens de magnitude mais rápido. O hook de eventos deve tratar a tecla `ESC` e o botão de fechar (`X`) da mesma forma: libertar tudo e sair.

#### 📋 Divisão de Tarefas

##### Dev A — Janela e Buffer

* [ ] Inicializar `mlx_init`, `mlx_new_window`
* [ ] Criar imagem com `mlx_new_image` e obter endereço do buffer
* [ ] Implementar função de `put_pixel` diretamente no buffer

##### Dev B — Eventos e Ciclo de Vida

* [ ] Registar hooks: keypress (`ESC`), close (botão vermelho), destroy
* [ ] Implementar função de saída limpa (liberta janela, imagem e cena)
* [ ] Testar troca de janela e minimização sem travar

#### 💻 Exemplo: Put Pixel no Buffer

```c
void img_put_pixel(t_img *img, int x, int y, int color)
{
    char *dst;

    dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
    *(unsigned int *)dst = color;
}

```

#### 📚 Referências

* **MiniLibX man pages:** `mlx_new_image`, `mlx_hook`.
* **42 Paris MiniLibX repo:** Fontes para entender bpp e endianness.

---

### 4️⃣ Fase 4 · Câmara — Geração de Raios

> **Resumo:** FOV, plano de projeção, um raio por pixel.

#### 💡 Tutorial de Apoio

Para cada pixel do ecrã, calculem um raio que parte da câmara (posição `C`) e atravessa um plano de projeção virtual definido pelo FOV. A orientação da câmara define os eixos locais (`forward`, `right`, `up`); o FOV horizontal determina a largura desse plano. Esta é a fase onde as duas fases anteriores (vetores + janela) se encontram.

#### 📋 Divisão de Tarefas

##### Dev A — Base Ortonormal

* [ ] Construir os vetores `forward`/`right`/`up` da câmara
* [ ] Calcular largura/altura do plano de projeção a partir do FOV
* [ ] Tratar casos degenerados (orientação próxima do eixo `up` global)

##### Dev B — Loop de Raios

* [ ] Calcular direção do raio normalizada para cada pixel `(x, y)`
* [ ] Implementar `t_ray { origem, direção }`
* [ ] Ligar o loop ao render principal (testar com gradiente de fundo)

#### 💻 Exemplo: Cálculo do Raio

```c
t_ray camera_get_ray(t_camera *cam, int px, int py, int w, int h)
{
    double u = (px + 0.5) / w * 2.0 - 1.0;
    double v = 1.0 - (py + 0.5) / h * 2.0;
    t_vec3 dir = vec3_add(cam->forward,
        vec3_add(vec3_scale(cam->right, u * cam->half_w),
                  vec3_scale(cam->up, v * cam->half_h)));
    return ((t_ray){cam->pos, vec3_normalize(dir)});
}

```

#### 📚 Referências

* **Scratchapixel — Generating Camera Rays:** Derivação matemática do plano de projeção.
* **Ray Tracing in One Weekend — Camera:** Implementação prática.

---

### 5️⃣ Fase 5 · Geometria — Motor de Interseções

> **Resumo:** Esfera, plano, cilindro — interseção mais próxima e normais.

#### 💡 Tutorial de Apoio

Cada objeto precisa de uma função `intersect(raio) → t mais próximo` e de uma função para calcular a normal no ponto de impacto. A esfera usa uma equação quadrática; o plano é uma divisão simples; o cilindro é o mais delicado, pois tem de tratar a superfície lateral e as duas tampas (*caps*).

#### 📋 Divisão de Tarefas

##### Dev A — Esfera e Plano

* [ ] Implementar interseção raio-esfera (equação quadrática)
* [ ] Implementar interseção raio-plano
* [ ] Implementar cálculo da normal para cada um

##### Dev B — Cilindro e Hits

* [ ] Implementar interseção raio-cilindro (lateral + 2 tampas)
* [ ] Implementar estrutura `t_hit` e percorrer a cena devolvendo o hit mais próximo
* [ ] Tratar caso do raio iniciar dentro de um objeto

#### 💻 Exemplo: Interseção da Esfera

```c
int sphere_hit(t_sphere *sp, t_ray r, double *t)
{
    t_vec3 oc = vec3_sub(r.origin, sp->center);
    double a = vec3_dot(r.dir, r.dir);
    double b = 2.0 * vec3_dot(oc, r.dir);
    double c = vec3_dot(oc, oc) - sp->radius * sp->radius;
    double disc = b * b - 4 * a * c;

    if (disc < 0)
        return (0);
    *t = (-b - sqrt(disc)) / (2.0 * a);
    return (*t > 0.0001);
}

```

#### 📚 Referências

* **Scratchapixel — Ray-Sphere & Ray-Plane Intersection:** Matemática passo a passo.
* **Scratchapixel — Ray-Cylinder Intersection:** Detalhes das tampas do cilindro.

---

### 6️⃣ Fase 6 · Luz — Modelo de Iluminação

> **Resumo:** Luz ambiente, difusa (Lambert) e sombras duras.

#### 💡 Tutorial de Apoio

A cor final resulta de: **ambiente** (constante) + **difusa** (proporcional ao ângulo entre a normal e a luz, lei de Lambert). Para sombras, dispara-se um segundo raio do ponto de impacto até à luz; se atingir algo no caminho, está em sombra. Evitem o *shadow acne* aplicando um pequeno *bias* (epsilon) na origem do raio de sombra.

#### 📋 Divisão de Tarefas

##### Dev A — Ambiente e Difusa

* [ ] Implementar componente ambiente (`ratio × cor`)
* [ ] Implementar componente difusa (`max(0, dot(N, L)) × intensidade × cor`)
* [ ] Combinar componentes e aplicar `clamp` RGB `[0, 255]`

##### Dev B — Sombras

* [ ] Implementar *shadow ray* do ponto de impacto até à luz
* [ ] Aplicar *bias* (epsilon) na origem para evitar *shadow acne*
* [ ] Testar projeção de sombras entre múltiplos objetos

#### 💻 Exemplo: Difusa de Lambert

```c
double diffuse_intensity(t_vec3 normal, t_vec3 light_dir, double light_ratio)
{
    double d = vec3_dot(normal, light_dir);

    if (d < 0)
        d = 0;
    return (d * light_ratio);
}

```

#### 📚 Referências

* **Scratchapixel — Light Transport & Shading:** Modelo Lambertiano.
* **Ray Tracing in One Weekend — Diffuse Materials:** Prática de sombreamento.

---

### 7️⃣ Fase 7 · Integração — Testes e Validação Final

> **Resumo:** Conexão de módulos, cenas de teste, verificação de leaks e defesa.

#### 💡 Tutorial de Apoio

Fase de junção: liguem parser → câmara → interseções → luz → buffer de imagem no loop principal. Criem ficheiros `.rt` de teste cobrindo casos limite (objetos isolados, sobrepostos, entradas inválidas). Verifiquem memory leaks e certifiquem-se que a Norm está impecável.

#### 📋 Divisão de Tarefas

##### Dev A — Robustez e Performance

* [ ] Ligar todas as fases no main loop de render
* [ ] Testar casos de erro no parser e garantir saída limpa sem leaks (`valgrind`/`leaks`)
* [ ] Otimizar cálculos desnecessários por pixel

##### Dev B — Testes e Documentação

* [ ] Criar conjunto de cenas `.rt` de teste
* [ ] Comparar imagens geradas com os exemplos do subject
* [ ] Finalizar `README.md` com as secções obrigatórias (`Description`, `Instructions`, `Resources`)

#### 📋 Checklist Pré-Defesa

* [ ] `norminette` sem erros (incluindo diretório de bónus, se houver)
* [ ] Compilação limpa com `-Wall -Wextra -Werror`
* [ ] Sem memory leaks (`valgrind --leak-check=full`)
* [ ] `ESC` e clique no botão `X` fecham a aplicação suavemente
* [ ] Saída uniforme `Error\n` para qualquer input inválido

---

### 8️⃣ Fase 8 · Bónus — Funcionalidades Avançadas (Opcional)

> **Resumo:** Phong, checkerboard, cone, bump mapping.

#### 💡 Tutorial de Apoio

*Atenção: Os bónus só são avaliados se a parte obrigatória estiver 100% perfeita.* Escolham 2 ou 3 bónus realistas. Reflexão especular (Phong) e *checkerboard* têm um ótimo impacto visual com esforço moderado.

#### 📋 Divisão de Tarefas

##### Dev A — Sombreamento Avançado

* [ ] Implementar componente especular (Reflexão de Phong)
* [ ] Implementar padrão *checkerboard* (xadrez procedural)
* [ ] Suportar múltiplas luzes com cores

##### Dev B — Geometria e Texturas Extra

* [ ] Implementar interseção de Cone
* [ ] Implementar *bump mapping* simples sobre a esfera
* [ ] Atualizar o parser `.rt` para os novos campos

#### 💻 Exemplo: Reflexão Especular (Phong)

```c
double specular_intensity(t_vec3 normal, t_vec3 light_dir, t_vec3 view_dir, double shininess)
{
    t_vec3 reflect = vec3_sub(vec3_scale(normal, 2 * vec3_dot(normal, light_dir)), light_dir);
    double spec = vec3_dot(reflect, view_dir);

    if (spec < 0)
        return (0);
    return (pow(spec, shininess));
}

```

---

## 📖 Recursos e Leituras Recomendadas

* [Ray Tracing in One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html)
* [Scratchapixel 2.0 — Computer Graphics from Scratch](https://www.scratchapixel.com/)
* [3Blue1Brown — Essência da Álgebra Linear](https://www.youtube.com/playlist?list=PLZHQObOWTQDPD3MizzM2xVFitgF8hE_ab)
