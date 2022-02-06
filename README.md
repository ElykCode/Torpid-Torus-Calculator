# Torpid-Torus-Calculator

Possibly the worst C++ code ever written, but I've never really written C++ before and I have to start somewhere. I like calculating tire volumes, so that's what I did here.

For reference, a tire is ROUGHLY a torus, which is basically just a cylinder stretched around a circle. 
We can approximately calculate the volume of a tire by treating it like a torus. 

The formula for a torus is as follows: `V = (pi*r^2)(2*pi*R)`, where V is volume, r is the minor radius, and R is the major radius. This can be broken down to `V = pi * r^2 * 2 * pi * R`, which is what we will use.

The minor radius is the radius of the stretched cylinder, and the major radius is the radius of the circle the cylinder is stretched around.
