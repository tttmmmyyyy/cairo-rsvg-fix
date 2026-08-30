# Cairo.Rsvg

Defined in cairo-rsvg-fix@0.2.0

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