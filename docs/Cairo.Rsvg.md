# Cairo.Rsvg

Defined in cairo-rsvg-fix@0.2.0

Renders SVG images onto Cairo contexts by librsvg.

`render_svg` draws an SVG image at its intrinsic size, which `get_intrinsic_size` returns.

## Examples

```fix
let svg = "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"2\" height=\"2\"><rect width=\"2\" height=\"2\" fill=\"white\"/></svg>";
assert_eq(|_|"", *get_intrinsic_size(svg), some((2.0, 2.0)));;
let surface = *ImageSurface::create(argb, (4_I32, 2_I32));
let cairo = *Cairo::create(surface);
render_svg(svg, (2.0, 0.0), cairo);;
// The image covers the right half of the surface, and the left half stays transparent black.
let data = *surface.get_data;
assert_eq(|_|"", data.@(0), 0_U8);;
assert_eq(|_|"", data.@(2 * 4), 255_U8)
```

## Values

### namespace Cairo.Rsvg

#### get_intrinsic_size

Type: `Std::String -> Std::IO (Std::Option (Std::F64, Std::F64))`

Returns the intrinsic size (width, height) of an SVG string in pixels.
Returns None if the size cannot be determined.

##### Parameters

* `svg` - SVG string (UTF-8).

#### render_svg

Type: `Std::String -> (Std::F64, Std::F64) -> Cairo::Cairo -> Std::IO ()`

Renders an SVG string onto a Cairo context at the given position.
Does nothing if rendering fails.

##### Parameters

* `svg` - SVG string (UTF-8).
* `pos` - Drawing origin in pixel coordinates (x, y).
* `cairo` - Cairo context.

## Types and aliases

## Traits and aliases

## Trait implementations