# shell-renderer

> Let's rotate those objects!


<!-- Project Shields -->
![contributors](https://img.shields.io/github/contributors/danmohedano/shell-renderer.svg?style=flat-square) [![license](https://img.shields.io/github/license/danmohedano/shell-renderer.svg?style=flat-square)](https://github.com/danmohedano/shell-renderer/blob/main/LICENSE) ![stars](https://img.shields.io/github/stars/danmohedano/shell-renderer.svg?style=flat-square) ![forks](https://img.shields.io/github/forks/danmohedano/shell-renderer.svg?style=flat-square) [![PRs welcome](https://img.shields.io/badge/PRs-welcome!-green.svg)](https://github.com/danmohedano/shell-renderer/issues)

<!-- TOC -->
## Table of Contents

- [But why?](#but-why)
- [But how (do I use it)?](#but-how-do-i-use-it)
- [But what?](#but-what)
- [But how (does it work)?](#but-how-does-it-work)
- [Roadmap](#roadmap)
- [Contributing](#contributing)
- [License](#license)

## But why?

The project was inspired by the famous [Have a donut.](https://www.a1k0n.net/2006/09/15/obfuscated-c-donut.html) post, which implements a rotating donut with donut-shaped code! I also find ASCII art to be very appealing, so a CLI renderer seemed like the logical approach for those two interests. In the end, it is just a fun project to work on.

## But how (do I use it)?

### Dependencies

None required. Just `cmake` for building purposes.

### Running

First, build the project and compile:
```
$ mkdir build && cd build
$ cmake ..
$ cmake --build .
```

The executables generated will be located in the `build/` directory you just created.

## But what?

For now, the project offers some very simple utility functions to render, which are showcased in several main programs.

### Basic Render

Implemented in `src/test.cpp`. Renders a squared plane to test the correct implementation of the logic behind the rendering.

### Rotating Cube

Implemented in `src/cube.cpp`. Renders a 3D cube while rotating it, showcasing rendering of points with fixed values. In this case, each face of the cube is rendered with a different character.

![cube](https://user-images.githubusercontent.com/43313293/203396679-6c285c60-3b92-4c2d-8705-810350cbc4d4.gif)

### Luminance

Implemented in `src/luminance.cpp`. Renders a 3D cube while rotating it while also taking into consideration the luminance of each face (amount of light reflected), updating the character used for rendering depending on the luminance value.

![luminance](https://user-images.githubusercontent.com/43313293/203396684-19ce9476-085d-4cb8-a95e-94f8d9b61d31.gif)

## But how (does it work)?

The program performs a very simple [Rasterization rendering](https://en.wikipedia.org/wiki/Rasterisation) by using a frame buffer and a Z-buffer, which is a very common technique. 

The renderer is configured to have a "virtual screen", where the 3D points are mapped into 2D space, which is then showed in the real screen using ASCII characters. The maths behind it can be boiled down to very basic trigonometry. For more information, check out [Donut math: how donut.c works](https://www.a1k0n.net/2011/07/20/donut-math.html).

## Roadmap

- [ ] Additional more complex examples

See the [open issues](https://github.com/danmohedano/shell-renderer/issues) for a full list of proposed features (and known issues). 

## Contributing

If you have ideas on how to improve the project, go ahead!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## License

Distributed under the [BSD-3-Clause](https://github.com/danmohedano/shell-renderer/blob/main/LICENSE) license © [danmohedano](https://github.com/danmohedano)