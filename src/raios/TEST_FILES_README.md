# Ficheiros de Teste - MiniRT Ray Tracer

Este diretório contém vários ficheiros de teste (`.rt`) para validar diferentes funcionalidades do ray tracer MiniRT.

## Ficheiros Disponíveis

### 1. `space.rt` (Ficheiro Original)
**Propósito**: Teste básico simples  
**Conteúdo**:
- 1 Luz
- 1 Plano
- 1 Esfera
- 1 Cilindro
- Câmera simples

**Uso**: Teste de baseline para verificar funcionamento básico

---

### 2. `simple_test.rt` (Teste Simples)
**Propósito**: Teste de múltiplos objetos com iluminação básica  
**Conteúdo**:
- Ambient lighting básico
- Câmera frontal
- 1 Luz principal
- 3 Planos (chão, fundo, lateral)
- 3 Esferas
- 1 Cilindro central

**Uso**: Validar renderização básica de múltiplos objetos

---

### 3. `test_scene.rt` (Teste Elaborado)
**Propósito**: Cena complexa com muitos objetos  
**Conteúdo**:
- Ambient lighting variável
- 2 Luzes (branca e azul)
- 1 Plano (chão)
- 9 Esferas (cores variadas e diferentes tamanhos)
- 4 Cilindros (orientações e cores diferentes)

**Uso**: Teste completo de renderização com múltiplas geometrias

---

### 4. `geometry_test.rt` (Teste de Geometrias)
**Propósito**: Teste isolado de cada tipo de objeto  
**Conteúdo**:
- 4 Esferas (tamanhos progressivos)
- 2 Planos (paredes lateral)
- 3 Cilindros (eixos diferentes)
- Iluminação dupla

**Uso**: Validar geometria individual de cada tipo

---

### 5. `lighting_test.rt` (Teste de Iluminação)
**Propósito**: Teste de sombras e efeitos de luz  
**Conteúdo**:
- Ambient lighting muito baixo
- 3 Luzes (branca, vermelha, azul)
- Planos para demonstrar sombras
- Esferas com diferentes níveis de brilho

**Uso**: Validar sistema de iluminação e sombras

---

## Formato dos Ficheiros .rt

### Sintaxe Geral

```
# Comentários começam com #

# Ambient Lighting
A <ratio> <r>,<g>,<b>
  ratio: 0.0 a 1.0 (intensidade da luz ambiente)
  r,g,b: 0-255 (cor)

# Camera
C <x,y,z> <dirx,diry,dirz> <fov>
  x,y,z: Posição da câmera
  dirx,diry,dirz: Vetor de direção normalizado
  fov: Campo de visão em graus (0-180)

# Light
L <x,y,z> <ratio> <r>,<g>,<b>
  x,y,z: Posição da luz
  ratio: 0.0 a 1.0 (intensidade)
  r,g,b: 0-255 (cor)

# Plane
pl <x,y,z> <normx,normy,normz> <r>,<g>,<b>
  x,y,z: Ponto no plano
  normx,normy,normz: Vetor normal (deve estar normalizado)
  r,g,b: 0-255 (cor)

# Sphere
sp <x,y,z> <diameter> <r>,<g>,<b>
  x,y,z: Centro da esfera
  diameter: Diâmetro da esfera
  r,g,b: 0-255 (cor)

# Cylinder
cy <x,y,z> <dirx,diry,dirz> <diameter> <height> <r>,<g>,<b>
  x,y,z: Centro da base
  dirx,diry,dirz: Vetor de direção do eixo (deve estar normalizado)
  diameter: Diâmetro do cilindro
  height: Altura do cilindro
  r,g,b: 0-255 (cor)
```

## Como Usar

```bash
# Compilar o projeto
cd src/raios
make

# Executar com um ficheiro de teste
./raios simple_test.rt
./raios test_scene.rt
./raios geometry_test.rt
./raios lighting_test.rt
```

## Checklist de Testes

Use estes ficheiros para validar:

- [ ] **Câmera**: Posicionamento e direção corretos
- [ ] **Iluminação Ambiente**: Luz de fundo uniforme
- [ ] **Luzes Pontuais**: Iluminação direcional e sombras
- [ ] **Esferas**: Renderização correta, intersecção raio-esfera
- [ ] **Cilindros**: Renderização e orientação corretas
- [ ] **Planos**: Infinitos em ambas as direções
- [ ] **Cores**: RGB correto em todos os objetos
- [ ] **Sombras**: Visibilidade e atenuação de luz
- [ ] **Antialiasing**: Suavização de bordas (se implementado)

## Notas Importantes

1. **Direções Normalizadas**: Vetores de direção e normais devem estar normalizados (magnitude = 1.0)
2. **Cores**: Valores RGB devem estar entre 0 e 255
3. **Coordenadas**: Sistema de coordenadas padrão (X, Y, Z)
4. **FOV**: Campo de visão em graus (recomendado: 45-90)

## Problemas Comuns

| Problema | Causa Provável | Solução |
|----------|----------------|---------|
| Imagem completamente preta | Câmera fora de posição | Ajustar coordenadas C |
| Iluminação fraca | Ambient muito baixo | Aumentar ratio em A |
| Objetos não aparecem | Fora do plano de câmera | Ajustar posição de C |
| Cores incorretas | Valores RGB > 255 | Usar valores 0-255 |

---

**Data de Criação**: 2026-08-06  
**Versão**: 1.0
