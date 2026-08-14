# Relatorio de testes da lib_vec3

Comando usado para compilar:

```sh
gcc -Wall -Wextra -Werror src/lib_vec3/*.c -lm -o /tmp/lib_vec3_tests
```

Comando usado para executar:

```sh
/tmp/lib_vec3_tests
```

## Resultados

| Teste | Entrada | Esperado | Obtido | Resultado |
| --- | --- | --- | --- | --- |
| `vec3_add` | `(1, 2, 3) + (4, -5, 6)` | `(5, -3, 9)` | `(5, -3, 9)` | OK |
| `vec3_sub` | `(1, 2, 3) - (4, -5, 6)` | `(-3, 7, -3)` | `(-3, 7, -3)` | OK |
| `vec3_scale` | `(1, 2, 3) * 2.5` | `(2.5, 5, 7.5)` | `(2.5, 5, 7.5)` | OK |
| `vec3_dot` | `(1, 2, 3) . (4, -5, 6)` | `12` | `12` | OK |
| `vec3_cross` | `(1, 2, 3) x (4, -5, 6)` | `(27, 6, -13)` | `(27, 6, -13)` | OK |
| `vec3_length` | `length(3, 4, 12)` | `13` | `13` | OK |
| `vec3_normalize` | `normalize(0, 3, 4)` | `(0, 0.6, 0.8)` | `(0, 0.6, 0.8)` | OK |
| `vec3_rotate` | rotacao de `(1, 0, 0)` no eixo Z por `pi / 2` | `(0, 1, 0)` | `(0, 1, 0)` | OK |

Resultado final: **8/8 testes passaram**.

## Observacoes

- Foi corrigido o arquivo de escala para `vec3_scale.c` e a funcao para `vec3_scale`, coincidindo com o prototipo declarado em `vec3.h`.
- Foi corrigido o sentido da rotacao em `vec3_rotate`, ajustando os sinais dos termos com seno de acordo com a formula de Rodrigues.
