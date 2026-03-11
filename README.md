# cairo-rsvg-fix

Fix-lang binding to [librsvg](https://gitlab.gnome.org/GNOME/librsvg), providing SVG rendering onto Cairo contexts.

This is a companion package to [cairo-fix](https://github.com/tttmmmyyyy/fixlang-cairo).

## Dependencies

* [Fix-lang](https://github.com/tttmmmyyyy/fixlang) must be installed.
* Requires cairo and librsvg >= 2.52.
  * The build script finds these libraries by pkg-config.

```
sudo apt update
sudo apt install -y pkg-config libcairo2-dev librsvg2-dev
```

## API

### `Cairo.Rsvg`

```
render_svg : String -> (F64, F64) -> Cairo -> IO ()
```

Renders an SVG string onto a Cairo context at the given pixel position `(x, y)`. Does nothing if rendering fails.

```
get_intrinsic_size : String -> IO (Option (F64, F64))
```

Returns the intrinsic size `(width, height)` of an SVG string in pixels. Returns `none()` if the size cannot be determined or the input is invalid.

## Usage

Add this package as a dependency in your `fixproj.toml`:

```toml
[[dependencies]]
name = "cairo-rsvg-fix"
version = "*"
git = { url = "https://github.com/tttmmmyyyy/fixlang-cairo-rsvg.git" }
```

Example:

```
import Cairo;
import Cairo.ImageSurface;
import Cairo.Rsvg;

main : IO ();
main = (
    let svg = "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"100\" height=\"100\">...</svg>";
    let surface = *ImageSurface::create(Format::argb, (100_I32, 100_I32));
    let cairo = *Cairo::create(surface);
    render_svg(svg, (0.0, 0.0), cairo);;
    surface.write_to_png("output.png")
);
```
