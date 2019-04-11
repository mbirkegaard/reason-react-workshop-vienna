type id = string;
type position = (float, float);

type marker = {
  id,
  position,
};

module Map = {
  [@react.component] [@bs.module "react-leaflet"]
  external make:
    (
      ~center: position,
      ~zoom: int,
      ~onClick: _ => unit,
      ~children: React.element
    ) =>
    React.element =
    "Map";
};

module TileLayer = {
  [@react.component] [@bs.module "react-leaflet"]
  external make: (~url: string, ~attribution: string) => React.element =
    "TileLayer";
};

module Marker = {
  [@react.component] [@bs.module "react-leaflet"]
  external make:
    (~position: position, ~onClick: 'e => unit, ~children: React.element=?) =>
    React.element =
    "Marker";
};

module Popup = {
  [@react.component] [@bs.module "react-leaflet"]
  external make: (~children: React.element) => React.element = "Popup";
};
