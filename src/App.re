let s = ReasonReact.string;

open Leaflet;
[@react.component]
let make = () =>
  <div style={ReactDOMRe.Style.make(~height="98vh", ())}>
    <Map center=(51., 0.9) zoom=13.>
      <TileLayer
        url="http://{s}.tile.osm.org/{z}/{x}/{y}.png"
        attribution="&copy; <a href='http://osm.org/copyright'>OpenStreetMap</a> contributors"
      />
    </Map>
  </div>;