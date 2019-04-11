let s = ReasonReact.string;
let a = ReasonReact.array;

let coordToPos: Data.coordinates => Leaflet.position =
  ({lat, lng}) => (lat, lng);

open Leaflet;
[@react.component]
let make = () => {
  let markers =
    Data.cities
    |> List.map((x: Data.city) =>
         <Marker position={x.Data.coordinates |> coordToPos} key={x.Data.id}>
           <Popup>
             <span> {s(x.name)} </span>
             <img src={x.image.url} width="300px" />
           </Popup>
         </Marker>
       )
    |> Array.of_list;

  <div style={ReactDOMRe.Style.make(~height="98vh", ())}>
    <Map center={List.hd(Data.cities).coordinates |> coordToPos} zoom=13>
      <TileLayer
        url="http://{s}.tile.osm.org/{z}/{x}/{y}.png"
        attribution="&copy; <a href='http://osm.org/copyright'>OpenStreetMap</a> contributors"
      />
      {a(markers)}
    </Map>
  </div>;
};