*This project has been created as part of the 42 curriculum by jmutumbu, lvitorin.*

# miniRT

## Description

miniRT is a minimal ray tracer written in C, built as part of the 42 school curriculum. The goal is to render 3D scenes described in `.rt` files by simulating the physical behavior of light rays — computing intersections with geometric primitives, applying diffuse lighting, ambient light, and shadows.

The renderer supports the following primitives:

- Sphere (`sp`)
- Plane (`pl`)
- Cylinder (`cy`) with capped ends

Each scene is defined by exactly one ambient light (`A`), one camera (`C`), one point light (`L`), and any number of objects. The output is displayed in a window using the MiniLibX graphics library.

## Instructions

### Requirements

- Linux
- GCC
- X11 and Xext development libraries

```bash
sudo apt install libx11-dev libxext-dev
```

### Compilation

```bash
make
```

This builds the `miniRT` binary at the root of the repository.

To clean object files:

```bash
make clean
```

To remove everything including the binary:

```bash
make fclean
```

### Execution

```bash
./miniRT <scene.rt>
```

Example:

```bash
./miniRT maps/geometry_test.rt
```

### Scene file format

Each line in a `.rt` file defines one element:

| Identifier | Fields | Example |
|---|---|---|
| `A` | ratio (0–1) color | `A 0.2 255,255,255` |
| `C` | position orientation fov | `C 0,0,10 0,0,-1 70` |
| `L` | position ratio color | `L -5,5,5 0.8 255,255,255` |
| `sp` | center diameter color | `sp 0,0,0 4 255,0,0` |
| `pl` | point normal color | `pl 0,-1,0 0,1,0 120,120,120` |
| `cy` | center axis diameter height color | `cy 0,0,0 0,1,0 2 5 0,0,255` |

### Controls

| Key | Action |
|---|---|
| `ESC` | Close the window |

## Resources

### Ray tracing

- [_Ray Tracing in One Weekend_](https://raytracing.github.io/books/RayTracingInOneWeekend.html) — Peter Shirley. The primary reference for the ray-object intersection math and camera model used in this project.
- [Scratchapixel — Ray-Sphere Intersection](https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/ray-sphere-intersection.html)
- [Scratchapixel — Ray-Cylinder Intersection](https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/ray-cylinder-intersection.html)
- [Scratchapixel — Diffuse and Lambertian Shading](https://www.scratchapixel.com/lessons/3d-basic-rendering/introduction-to-shading/diffuse-lambertian-shading.html)

### MiniLibX

- [MiniLibX documentation (42 Lyon)](https://harm-smits.github.io/42docs/libs/minilibx)

### Use of AI

AI (Amazon Q) was used during this project strictly as a support tool for:

- **Debugging** — identifying the root cause of runtime errors, in particular a `get_next_line` implementation that reset its static buffer state on every call, causing the parser to read only the first line of any scene file.
- **Explanations** — clarifying concepts related to ray-cylinder intersection geometry and shadow bias techniques.

No AI was used to generate the core logic, algorithms, or structure of the project.
