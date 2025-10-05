# RGB Image Processing Pipeline (C++ - L.EIC009)

## Description
This project implements a C++ pipeline for manipulating 8-bit per channel RGB images using Scrim scripts (Script for images). It supports creating, transforming, and combining images with operations such as color inversion, grayscale conversion, fill, horizontal/vertical mirroring, image addition, cropping, resizing, rotation, and scaling. Advanced functionality includes the `chain` command, which executes multiple Scrim scripts sequentially while detecting recursive loops to prevent infinite execution.

Developed for the **Programming course (L.EIC009), April 2025**.

## Features
- Basic color and pixel manipulation (`Color`, `Image`)
- Simple transformation commands (`invert`, `to_gray_scale`, `fill`, `h_mirror`, `v_mirror`, `add`, `move`, `slide`)
- Dimension-changing commands (`crop`, `resize`, `rotate_left`, `rotate_right`, `scaleup`)
- Run Scrim scripts via `runscrim`
- Automatic testing of functionality with `tester`
- Advanced `chain` command to execute multiple scripts in sequence with recursion detection

## Project Structure
- `include/` – headers for `Color`, `Image`, `Command`, and custom commands
- `src/` – implementation of classes and commands
- `main/` – executables `runscrim` and `tester`
- `output/` – generated images
- `input/` and `expected/` – Scrim scripts and expected output images

## How to Build
```bash
$ unzip project.zip
$ cd project
$ cmake -B build
$ cd build
$ make
