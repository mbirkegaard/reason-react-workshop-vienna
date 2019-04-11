type position = (float, float);

module Map = {
  [@react.component] [@bs.module "react-leaflet"]
  external make:
    (~center: position, ~zoom: int, ~children: React.element) => React.element =
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
    (~position: position, ~children: React.element) => React.element =
    "Marker";
};

module Popup = {
  [@react.component] [@bs.module "react-leaflet"]
  external make: (~children: React.element) => React.element = "Popup";
};