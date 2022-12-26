# fract-ol
 
<p align="center">
<img src="https://github.com/santiagotena/assets/blob/master/logos/42%20logo.jpeg?raw=true" alt="42 Wolfsburg Logo" width="150" height="150">
</p>
 
This is one of the first graphical projects from 42 Wolfsburg. The aim is to render fractals, abstract mathematical objects whose pattern remains the same at every scale. By using numerical computing, we are able to run the calculations needed to represent complex numbers in a two dimensional plane.
 
For this project we must use the 42 Network graphical library called MiniLibX. This library was
developed internally and includes basic necessary tools to open a window, create images
and deal with keyboard and mouse events. In other words, this was an opportunity to get familiar with event handling.
 
# Usage
 
Use `make` to compile the program.
 
There are two possible fractals that can be deployed:
<ul>
<li> Mandelbort </li>
<li> Julia </li>
</ul> 
 
For execution use the following inputs within the terminal:
 
### Mandelbrot
```
./fractol mandelbrot
```
 
### Julia
```
./fractol julia <real_number> <imaginary_number>
```

Example: 
```
./fractol julia -0.77 -0.09
 ```
 
# Screenshots
## Mandelbrot
<p align="center">
<img src="https://github.com/santiagotena/fract-ol/blob/master/screenshots/mandelbrot.png?raw=true" alt="Mandelbrot image">
</p>
 
## Julia
<p align="center">
<img src="https://github.com/santiagotena/fract-ol/blob/master/screenshots/julia.png?raw=true" alt="Julia image one">
</p>
<p align="center">
<img src="https://github.com/santiagotena/fract-ol/blob/master/screenshots/julia_zoom.png?raw=true" alt="Julia image two">
</p>
 
