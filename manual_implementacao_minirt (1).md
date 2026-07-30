# Manual de Implementação — miniRT

*Guia de estudo e implementação para a dupla, organizado pelas 9 fases do roadmap, cruzando os conceitos de "Ray Tracing in One Weekend" (Shirley, Black & Hollasch) com os requisitos exatos do subject da École 42.*

## Como usar este manual

Cada fase segue sempre a mesma estrutura:

1. **Domínio esperado no final da fase** — o que cada elemento da dupla deve conseguir explicar e implementar sozinho, sem ajuda, na defesa.
2. **C aplicado** — o conceito de linguagem C e de Norm que a fase exercita.
3. **Estrutura de dados e interface (entrada → saída)** — os `structs` e assinaturas de função que definem o contrato entre os dois elementos. Um elemento pode implementar o lado de dentro de uma função sem saber como o outro implementou a sua, desde que ambos respeitem esta interface.
4. **Matemática de vetores** — a ferramenta matemática mínima necessária, explicada de forma aplicada.
5. **Luz e shading** — só presente nas fases onde o modelo de iluminação evolui.
6. **Passo a passo de implementação** — sequência concreta de trabalho.
7. **Armadilhas comuns** — erros típicos que fazem perder horas de debug.
8. **Auto-teste** — pergunta ou exercício que confirma que a fase foi mesmo compreendida.
9. **Checklist Norm** — pontos de atenção específicos da correção normativa da 42.
10. **Leituras** — capítulos do livro e outras referências relevantes.

### Como trabalhar de forma independente

A regra de ouro: **um contrato de função (nome, tipos de entrada, tipo e significado da saída) é decidido em conjunto antes de qualquer um escrever o corpo da função.** A partir daí, cada elemento pode implementar o seu lado sozinho e testá-lo com dados fictícios, sem esperar pelo códigminilibxo do outro — desde que respeite exatamente a assinatura combinada. Se um contrato precisar de mudar a meio da fase, é uma decisão de dupla, não uma decisão unilateral, porque o outro lado já pode estar a depender dele.

Um aviso geral sobre o livro: ele é escrito em C++ e implementa um *path tracer* estocástico (amostragem aleatória, recursão de raios, materiais). O vosso subject pede um modelo **determinístico** em C puro. Usem o livro para entender a arquitetura e a matemática — nunca para copiar diretamente a sintaxe ou o modelo de shading estocástico na parte obrigatória.

---

## Parte 0 — Fundamentos transversais

Antes da Fase 0, alinhem estes três blocos de conhecimento em conjunto, como dupla.

### 0.1 C aplicado a gráficos

- **Sem classes, sem herança.** Um objeto "polimórfico" (esfera, plano, cilindro) vira um `struct` com um campo `t_obj_type` (enum) e um ponteiro `void *data` para os dados específicos do tipo.
- **Gestão de memória explícita.** Quem aloca uma estrutura escreve a função `free` equivalente no mesmo commit.
- **Norm 42:** funções curtas (tipicamente até 25 linhas), poucos parâmetros por função (tipicamente até 4), poucas funções por ficheiro `.c` (tipicamente até 5), uma variável por linha, sem atribuições múltiplas. Confirmem sempre a versão exata do `norminette` da vossa promoção.
- **Sem exceções.** Todo o erro é valor de retorno (0/1, ou `NULL`) verificado explicitamente.

### 0.2 Matemática de vetores aplicada

| Operação | Fórmula | Onde se usa |
|---|---|---|
| Soma / subtração | `(ax+bx, ay+by, az+bz)` | deslocar pontos, calcular direções |
| Escala | `(a·x, a·y, a·z)` | avançar ao longo de um raio (`origem + t·direção`) |
| Produto escalar (`dot`) | `ax·bx + ay·by + az·bz` | ângulo entre normal e luz, projeções |
| Produto vetorial (`cross`) | regra da mão direita | construir bases ortonormais (right/up) |
| Norma / normalização | `sqrt(dot(v,v))`, depois dividir | garantir vetores de direção unitários |

Regra prática: qualquer vetor que representa uma **direção** deve estar normalizado antes de ser usado num cálculo de ângulo ou de shading.

### 0.3 Conceitos de luz essenciais

1. **Ambiente** — constante `ratio × cor` aplicada a todos os pontos da cena.
2. **Difusa (Lambert)** — intensidade proporcional a `max(0, dot(normal, direção_para_a_luz))`.
3. **Sombra dura** — um segundo raio, do ponto de impacto até à luz; se encontrar outro objeto, anula a componente difusa.

---

## Fase 0 — Fundação do repositório

**Domínio esperado:** ambos conseguem explicar, sem olhar para o Makefile, o que cada regra obrigatória faz.

**C aplicado:** organização de projeto C multi-ficheiro; regras de Makefile; flags `-Wall -Wextra -Werror`.

**Estrutura de dados e interface (entrada → saída):**

Nesta fase só existe um contrato — o ponto de entrada do programa. Tudo o resto ainda não tem forma definida.

```c
int main(int argc, char **argv);
```

| | Tipo | Significado |
|---|---|---|
| Entrada | `argc`, `argv` | `argv[1]` deve ser o caminho de um ficheiro `.rt` |
| Saída | `int` (exit code) | `0` = sucesso; `1` = erro, já reportado em `stderr` como `"Error\n"` + mensagem |

Como ainda não há parser nem scene, o `main` desta fase só valida `argc == 2` e a extensão `.rt` do nome do ficheiro — nada mais.

**Matemática de vetores:** nenhuma ainda.

**Passo a passo:**
1. Estrutura de pastas (`src/`, `includes/`, `libft/`).
2. Makefile com todas as regras obrigatórias, incluindo `bonus`.
3. Integração da libft com o seu próprio Makefile.
4. `main.c` mínimo com o contrato acima.

**Armadilhas comuns:** Makefile que faz relink desnecessário; ficheiros de bónus fora da verificação da Norm.

**Auto-teste:** apagar o binário, correr `make`, explicar exatamente que comandos foram executados.

**Checklist Norm:** `$(NAME)`, `all`, `clean`, `fclean`, `re`, `bonus` presentes; sem relink supérfluo.

**Leituras:** capítulo 1 (Overview) do livro — o capítulo 2 usa `iostream` para gerar um ficheiro PPM, o que não se aplica ao vosso projeto.

---

## Fase 1 — Biblioteca de vetores 3D

**Domínio esperado:** qualquer um dos dois deriva no quadro a fórmula de normalização e explica o que o produto escalar representa geometricamente.

**C aplicado:** `struct` devolvido por valor; funções puras sem efeitos secundários; `double` para precisão.

**Estrutura de dados e interface (entrada → saída):**

```c
typedef struct s_vec3
{
    double  x;
    double  y;
    double  z;
}   t_vec3;

t_vec3  vec3_add(t_vec3 a, t_vec3 b);
t_vec3  vec3_sub(t_vec3 a, t_vec3 b);
t_vec3  vec3_scale(t_vec3 v, double s);
double  vec3_dot(t_vec3 a, t_vec3 b);
t_vec3  vec3_cross(t_vec3 a, t_vec3 b);
double  vec3_length(t_vec3 v);
t_vec3  vec3_normalize(t_vec3 v);
t_vec3  vec3_rotate(t_vec3 v, t_vec3 axis, double angle_rad);
```

| Função | Entrada | Saída |
|---|---|---|
| `vec3_add` / `vec3_sub` | dois `t_vec3` | `t_vec3` resultante, mesma unidade que a entrada |
| `vec3_scale` | um `t_vec3`, um `double` | `t_vec3` escalado |
| `vec3_dot` | dois `t_vec3` | `double` (escalar; se ambos unitários, é o cosseno do ângulo entre eles) |
| `vec3_cross` | dois `t_vec3` | `t_vec3` perpendicular a ambos, não normalizado |
| `vec3_length` | um `t_vec3` | `double` ≥ 0 |
| `vec3_normalize` | um `t_vec3` não nulo | `t_vec3` de comprimento 1; comportamento indefinido se a entrada for o vetor nulo — validem antes de chamar |
| `vec3_rotate` | vetor a rodar, eixo (assumido normalizado), ângulo em radianos | `t_vec3` rodado em torno do eixo |

Este ficheiro (`vec3.c`/`vec3_utils.c`) não depende de nenhuma outra fase — pode ser desenvolvido e testado por completo isoladamente, com um `main` de teste próprio.

**Matemática de vetores:** ver Parte 0.2 — esta fase implementa-a diretamente.

**Passo a passo:**
1. Definir `t_vec3`.
2. Implementar as operações da tabela, cada uma testada isoladamente.
3. Implementar rotação em torno de eixo arbitrário.

**Armadilhas comuns:** dividir por comprimento zero; trocar a ordem de `cross(a,b)` com `cross(b,a)` (não comutativo).

**Auto-teste:** com dois vetores unitários a 90°, calcular `dot` à mão e confirmar que o código devolve o mesmo valor.

**Checklist Norm:** cada função de vetor curta; se `vec3_normalize` estiver longa, faltam auxiliares.

**Leituras:** capítulo 3 (The vec3 Class).

---

## Fase 2 — Parser do ficheiro de cena `.rt`

**Domínio esperado:** qualquer um dos dois prevê, dado um `.rt` novo, exatamente que erro (ou sucesso) o parser reporta, campo a campo.

**C aplicado:** leitura linha a linha; tokenização manual; validação de intervalos; libertação em profundidade em caso de erro.

**Estrutura de dados e interface (entrada → saída):**

```c
typedef enum e_obj_type
{
    OBJ_SPHERE,
    OBJ_PLANE,
    OBJ_CYLINDER
}   t_obj_type;

typedef struct s_color
{
    int r;
    int g;
    int b;
}   t_color;

typedef struct s_object
{
    t_obj_type      type;
    void            *data;      /* aponta para t_sphere / t_plane / t_cylinder */
    t_color         color;
    struct s_object *next;
}   t_object;

typedef struct s_ambient
{
    double  ratio;
    t_color color;
}   t_ambient;

typedef struct s_light
{
    t_vec3  pos;
    double  ratio;
    t_color color;              /* usado só a partir do bónus */
}   t_light;

typedef struct s_scene
{
    t_ambient   ambient;
    t_camera    camera;         /* struct definida na Fase 4 */
    t_light     light;
    t_object    *objects;
}   t_scene;

int     scene_parse(char *filepath, t_scene *scene);
```

| | Tipo | Significado |
|---|---|---|
| Entrada | `filepath` | caminho do ficheiro `.rt` recebido em `argv[1]` |
| Entrada | `scene` | ponteiro para uma `t_scene` ainda vazia, a preencher |
| Saída | `int` | `0` = sucesso, `scene` preenchida e válida; `-1` = erro — `scene` já foi completamente libertada internamente e a mensagem de erro já foi impressa; quem chama não deve tentar libertar nada de novo |

Esta assinatura é o contrato mais importante do projeto: quem trabalha na Fase 4 em diante só precisa de saber que, depois de `scene_parse` devolver `0`, `scene.camera`, `scene.light`, `scene.ambient` e `scene.objects` estão preenchidos e válidos — não precisa de saber como o parser funciona por dentro.

**Matemática de vetores:** validação de que vetores lidos estão em `[-1,1]` por eixo.

**Passo a passo:**
1. Leitura linha a linha.
2. Identificar identificador e despachar para a função de parsing correspondente.
3. Cada função preenche a sua struct e valida os seus campos.
4. `A` e `C` só podem aparecer uma vez.
5. Erro → `"Error\n"` + mensagem, sem *leaks*.

**Armadilhas comuns:** números mal formados não detetados; espaços múltiplos não tolerados; libertação parcial em erro a meio da cena.

**Auto-teste:** 5 ficheiros `.rt` inválidos diferentes, todos terminando de forma limpa.

**Checklist Norm:** uma função por tipo de elemento, sem uma função gigante.

**Leituras:** o livro não tem parser de cena — usem o capítulo IV do subject como especificação exata.

---

## Fase 3 — Janela MiniLibX e loop de eventos

**Domínio esperado:** ambos explicam a diferença entre desenhar pixel a pixel e escrever diretamente no buffer da imagem.

**C aplicado:** aritmética de ponteiros sobre o buffer; manipulação de bits/bytes de cor; *callbacks* de eventos.

**Estrutura de dados e interface (entrada → saída):**

```c
typedef struct s_img
{
    void    *mlx_img;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
}   t_img;

typedef struct s_mlx
{
    void    *mlx;
    void    *win;
    t_img   image;
}   t_mlx;

int     window_init(t_mlx *mlx, int width, int height);
void    img_put_pixel(t_img *img, int x, int y, int color);
int     key_hook(int keycode, void *param);
int     close_hook(void *param);
```

| Função | Entrada | Saída |
|---|---|---|
| `window_init` | `mlx` a preencher, largura e altura em píxeis | `int` (`0` sucesso, `-1` falha ao abrir janela/imagem); preenche `mlx->mlx`, `mlx->win`, `mlx->image` |
| `img_put_pixel` | imagem já inicializada, coordenadas `x,y` dentro dos limites, `color` em formato `0xRRGGBB` | nada (`void`); escreve diretamente no buffer — quem chama garante que `x,y` estão dentro da imagem |
| `key_hook` | `keycode` da tecla premida, `param` (ponteiro genérico para `t_mlx`, convertido internamente) | `int` (valor de retorno exigido pela MiniLibX, tipicamente `0`); termina o programa se `keycode` for ESC |
| `close_hook` | `param` (ponteiro genérico para `t_mlx`) | `int`; termina o programa de forma limpa ao clicar no botão de fecho |

Quem trabalha nas fases seguintes só precisa de saber que, depois de `window_init` devolver `0`, pode chamar `img_put_pixel` para qualquer `(x,y)` dentro da imagem, e que o programa fecha sozinho de forma limpa via os hooks — não precisa de conhecer a implementação da MiniLibX por dentro.

**Matemática de vetores:** nenhuma nova.

**Passo a passo:**
1. Inicializar MiniLibX e janela.
2. Criar imagem, obter endereço do buffer.
3. Implementar `img_put_pixel`.
4. Registar hooks de teclado e fecho.
5. Confirmar fluidez ao trocar de foco/minimizar.

**Armadilhas comuns:** usar `mlx_pixel_put` em vez do buffer; esquecer de libertar imagem/janela no caminho de saída.

**Auto-teste:** explicar o percurso completo de um clique no botão de fechar até ao processo terminar.

**Checklist Norm:** callbacks curtos, delegando a funções auxiliares.

**Leituras:** documentação oficial da MiniLibX (`man mlx_new_image`, `man mlx_hook`) — o livro não tem equivalente.

---

## Fase 4 — Geração de raios e câmara

**Domínio esperado:** qualquer um dos dois deriva, a partir do FOV e da resolução, a direção do raio de um pixel qualquer.

**C aplicado:** primeiro ponto de integração real da dupla — recomenda-se revisão cruzada de código.

**Estrutura de dados e interface (entrada → saída):**

```c
typedef struct s_ray
{
    t_vec3  origin;
    t_vec3  dir;      /* sempre normalizado */
}   t_ray;

typedef struct s_camera
{
    t_vec3  pos;
    t_vec3  forward;
    t_vec3  right;
    t_vec3  up;
    double  half_w;
    double  half_h;
}   t_camera;

void    camera_build_basis(t_camera *cam, t_vec3 raw_orientation,
            double fov_deg, double aspect_ratio);
t_ray   camera_get_ray(t_camera *cam, int px, int py, int width, int height);
```

| Função | Entrada | Saída |
|---|---|---|
| `camera_build_basis` | `cam` com `pos` já preenchido pelo parser, `raw_orientation` (vetor lido do `.rt`), FOV em graus, aspect ratio da imagem | nada (`void`); preenche `forward`, `right`, `up`, `half_w`, `half_h` em `cam` — chamada **uma vez** por render, nunca por pixel |
| `camera_get_ray` | `cam` já com a base construída, coordenadas de pixel `px,py`, dimensões da imagem | `t_ray` com `origin = cam->pos` e `dir` normalizado — chamada **uma vez por pixel** |

Esta separação é o contrato chave da fase: quem trata da Fase 5 em diante só depende de `camera_get_ray` devolver um `t_ray` correto — não precisa de saber como a base ortonormal foi construída.

**Matemática de vetores:** `right = normalize(cross(world_up, forward))`; `up = cross(forward, right)`; meia-largura do plano via `tan(FOV/2)`.

**Passo a passo:**
1. Construir `right` e `up` a partir da orientação.
2. Calcular `half_w`/`half_h` a partir do FOV e aspect ratio.
3. Para cada pixel, combinar `forward`, `right`, `up` ponderados pela posição do pixel.
4. Testar só com gradiente de fundo, sem objetos.

**Armadilhas comuns:** trocar `right` por `left` (imagem espelhada); esquecer de normalizar a direção final; usar FOV vertical em vez do horizontal.

**Auto-teste:** câmara apontada para `(0,0,1)` — o raio central deve ser próximo de `(0,0,1)`, os raios dos quatro cantos simétricos entre si.

**Checklist Norm:** separar "construir base" (uma vez) de "raio por pixel" (por pixel) em funções distintas.

**Leituras:** capítulos 4 e 12 (Positionable Camera).

---

## Fase 5 — Motor de interseções

**Domínio esperado:** qualquer um dos dois explica geometricamente porque a interseção raio-esfera é quadrática e onde o cilindro exige tratamento separado das tampas.

**C aplicado:** abstração de "objeto" sem herança via `enum` + `switch`; struct `t_hit` a transportar o resultado de uma interseção.

**Estrutura de dados e interface (entrada → saída):**

```c
typedef struct s_hit
{
    double  t;
    t_vec3  point;
    t_vec3  normal;   /* sempre normalizado, sempre "para fora" do objeto */
    t_color color;
}   t_hit;

int     sphere_hit(t_object *obj, t_ray ray, double t_min, double t_max, t_hit *hit);
int     plane_hit(t_object *obj, t_ray ray, double t_min, double t_max, t_hit *hit);
int     cylinder_hit(t_object *obj, t_ray ray, double t_min, double t_max, t_hit *hit);
int     scene_closest_hit(t_scene *scene, t_ray ray, t_hit *hit);
```

| Função | Entrada | Saída |
|---|---|---|
| `sphere_hit` / `plane_hit` / `cylinder_hit` | `obj` (já convertido para o tipo concreto internamente via `obj->data`), `ray`, intervalo válido de `t` (`t_min`, `t_max` — tipicamente `0.0001` e `+infinito`) | `int` (`1` = há interseção válida dentro do intervalo, `hit` preenchido; `0` = não há) — todas as três funções partilham exatamente esta assinatura, para poderem ser chamadas de forma intercambiável |
| `scene_closest_hit` | `scene` já parseada, `ray` | `int` (`1` = algum objeto foi atingido, `hit` preenchido com o de menor `t`; `0` = raio não atinge nada) |

Quem implementa a Fase 6 só depende de `scene_closest_hit` devolver um `t_hit` correto — não precisa de saber a fórmula de interseção de nenhum objeto específico.

**Matemática de vetores:** equação quadrática `a·t² + b·t + c = 0` via `dot`; normal da esfera `(ponto - centro)/raio`; normal do plano é o próprio vetor armazenado; normal do cilindro por projeção sobre o eixo.

**Passo a passo:**
1. `sphere_hit` (quadrática, descartar raízes ≤ `t_min`).
2. `plane_hit` (divisão via `dot`).
3. `cylinder_hit` (lateral + duas tampas).
4. `scene_closest_hit` percorre todos os objetos e guarda o menor `t` positivo.
5. Tratar raio a começar dentro de um objeto (inverter normal se necessário).

**Armadilhas comuns:** esquecer as tampas do cilindro; `t` demasiado próximo de zero aceite como válido; normal invertida.

**Auto-teste:** renderizar uma esfera só com a normal como cor, confirmar gradiente esférico suave e simétrico.

**Checklist Norm:** uma função por tipo de objeto; `scene_closest_hit` sem lógica específica de nenhum tipo.

**Leituras:** capítulos 5 e 6 (incluindo front face vs. back face, 6.4); Scratchapixel para o cilindro (ausente do livro).

---

## Fase 6 — Modelo de iluminação

**Domínio esperado:** qualquer um dos dois calcula à mão, dado um ponto/normal/luz, a intensidade difusa esperada e prevê se o ponto está em sombra.

**C aplicado:** `clamp` explícito de cor a `[0,255]`; shadow ray reutilizando `scene_closest_hit` da Fase 5, sem duplicar lógica.

**Estrutura de dados e interface (entrada → saída):**

```c
int     is_in_shadow(t_scene *scene, t_vec3 point, t_vec3 light_dir, double light_dist);
double  compute_ambient(t_scene *scene);
double  compute_diffuse(t_hit *hit, t_light *light);
t_color shade_point(t_scene *scene, t_hit *hit);
```

| Função | Entrada | Saída |
|---|---|---|
| `is_in_shadow` | `scene`, `point` (já deslocado ao longo da normal — bias aplicado por quem chama, não por esta função), `light_dir` normalizado, `light_dist` (distância até à luz) | `int` (`1` = em sombra, `0` = luz visível) |
| `compute_ambient` | `scene` (usa `scene->ambient`) | `double` em `[0, ratio]`, a multiplicar depois pela cor do objeto |
| `compute_diffuse` | `hit` (usa `hit->normal`, `hit->point`), `light` | `double` em `[0, light->ratio]` |
| `shade_point` | `scene`, `hit` já preenchido por `scene_closest_hit` | `t_color` final, já com `clamp` a `[0,255]` aplicado — pronta a passar a `img_put_pixel` |

`shade_point` é a função de topo desta fase: combina internamente `compute_ambient`, `compute_diffuse` e `is_in_shadow`, e é a única que o ciclo de render (Fase 7) precisa de chamar.

**Matemática de vetores:** `dot(normal, direção_luz)` para difusa, ambos normalizados; subtração de pontos para obter direção da luz.

**Passo a passo:**
1. Ambiente como constante.
2. Difusa via `max(0, dot(normal, direção_luz)) × ratio`.
3. Combinar e aplicar `clamp` a `[0,255]`.
4. Shadow ray com bias na origem ao longo da normal.

**Armadilhas comuns:** esquecer `clamp`; esquecer bias (shadow acne); inverter a direção do shadow ray.

**Auto-teste:** esfera com luz lateral — gradiente suave na parte iluminada, transição nítida (sem ruído) na sombra projetada.

**Checklist Norm:** `compute_ambient`, `compute_diffuse` e `is_in_shadow` em funções distintas.

**Leituras:** capítulo 9 só para intuição física, não implementação (o modelo do livro é estocástico); Scratchapixel — "Light Transport and Shading".

---

## Fase 7 — Integração, testes e README

**Domínio esperado:** a dupla corre uma bateria de testes e explica o que cada cena verifica.

**C aplicado:** deteção de *memory leaks*; revisão final de Norm em todos os ficheiros.

**Estrutura de dados e interface (entrada → saída):**

```c
void    render_scene(t_scene *scene, t_mlx *mlx);
int     scene_free(t_scene *scene);
```

| Função | Entrada | Saída |
|---|---|---|
| `render_scene` | `scene` já parseada e válida, `mlx` já inicializado (janela e imagem prontas) | nada (`void`); percorre todos os píxeis, chama `camera_get_ray` → `scene_closest_hit` → `shade_point` → `img_put_pixel`, e por fim `mlx_put_image_to_window` — esta função é a costura entre todas as fases anteriores |
| `scene_free` | `scene` (parseada ou parcialmente parseada) | `int` (`0` sempre — não há caso de falha na libertação); percorre e liberta `scene->objects` e qualquer alocação interna |

Esta fase não introduz matemática nova — a interface acima é literalmente a soma das interfaces já definidas nas Fases 2 a 6.

**Passo a passo:**
1. Ligar parser → câmara → interseções → luz → buffer no `render_scene`.
2. Construir cenas `.rt` de teste (objeto único, sombras cruzadas, múltiplas luzes, erros propositados).
3. Correr deteção de leaks em todos os caminhos, incluindo os de erro.
4. Escrever `README.md` com as quatro secções obrigatórias.

**Armadilhas comuns:** testar só o caminho feliz; README sem a linha itálica exata pedida.

**Auto-teste:** cada elemento tenta "partir" o código do outro com ficheiros `.rt` inesperados.

**Checklist Norm:** `norminette` sobre o projeto completo, incluindo `_bonus.{c/h}`.

**Leituras:** capítulo V do subject (Readme Requirements).

---

## Fase 8 (Bónus) — Phong, checkerboard, cone, bump mapping

**Domínio esperado:** a dupla justifica, na defesa, a fórmula exata usada em cada bónus escolhido.

**C aplicado:** extensão do parser e das estruturas sem quebrar a parte obrigatória; isolamento em `_bonus.{c/h}`.

**Estrutura de dados e interface (entrada → saída):**

```c
double  compute_specular(t_hit *hit, t_light *light, t_vec3 view_dir, double shininess);
t_color checkerboard_color(t_hit *hit, t_color c1, t_color c2, double scale);
int     cone_hit(t_object *obj, t_ray ray, double t_min, double t_max, t_hit *hit);
```

| Função | Entrada | Saída |
|---|---|---|
| `compute_specular` | `hit`, `light`, `view_dir` (da superfície para a câmara, normalizado), `shininess` (expoente de brilho, ex. 32) | `double` em `[0,1]`, a somar às componentes ambiente e difusa já existentes de `shade_point` |
| `checkerboard_color` | `hit`, duas cores alternadas, `scale` (tamanho do quadrado do padrão) | `t_color` — substitui `hit->color` antes de `shade_point` ser chamada |
| `cone_hit` | mesma assinatura de `sphere_hit`/`plane_hit`/`cylinder_hit` — reaproveita o mesmo contrato da Fase 5 | `int` (mesmo significado que os outros `_hit`) |

Manter exatamente a mesma assinatura de `cone_hit` que os outros tipos de interseção é o que permite adicioná-lo a `scene_closest_hit` sem alterar essa função.

**Matemática de vetores:** `reflect = 2·dot(normal, luz)·normal - luz`; coordenadas UV para checkerboard/bump mapping.

**Passo a passo (escolham 2-3 bónus):**
1. Especular: `reflect` + fórmula de Phong.
2. Checkerboard: cor procedural pela paridade de coordenadas do ponto de impacto.
3. Cone: reaproveitar a estrutura de `cylinder_hit`, adaptando a equação.
4. Só depois de confirmarem que a parte obrigatória está completa e sem falhas.

**Armadilhas comuns:** avançar para bónus com o obrigatório incompleto; campos novos no `.rt` sem conseguir justificar na defesa.

**Auto-teste:** apresentar a fórmula de Phong um ao outro, sem consultar o código.

**Checklist Norm:** ficheiros de bónus com o mesmo rigor de Norm que os obrigatórios.

**Leituras:** capítulos 10 e 11; Scratchapixel — "Phong Reflection Model".

---

## Referências gerais (todas as fases)

- Shirley, Black & Hollasch — *Ray Tracing in One Weekend*, versão 4.0.2 — arquitetura e intuição matemática, não a implementação em C++ nem o modelo estocástico de luz.
- Scratchapixel — artigos de geometria, interseções e shading, alinhados com um modelo determinístico.
- Documentação oficial da MiniLibX (`man` pages das funções permitidas no subject).
- Subject oficial `en_subject.pdf` — fonte de verdade para qualquer dúvida de formato, ordem de campos ou critério de avaliação.
