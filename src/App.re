open Leaflet;

type state = list(marker);
type action =
  | AddMarker(position)
  | RemoveMarker(string);

[@react.component]
let make = (~initialMarkers=[]) => {
  let (state, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | AddMarker((x, y)) => [
            {id: {j|$x:$y|j}, position: (x, y)},
            ...state,
          ]
        | RemoveMarker(id) => state |> List.filter(marker => marker.id != id)
        },
      initialMarkers,
    );

  <Map
    center=(0.0, 0.0)
    zoom=5
    onClick={e => AddMarker((e##latlng##lat, e##latlng##lng)) |> dispatch}>
    <TileLayer
      attribution="&copy; <a href='http://osm.org/copyright'>OpenStreetMap</a> contributors"
      url="http://{s}.tile.osm.org/{z}/{x}/{y}.png"
    />
    {state
     |> List.map((marker: marker) =>
          <Marker
            key={marker.id}
            position={marker.position}
            onClick={_ => RemoveMarker(marker.id) |> dispatch}
          />
        )
     |> Array.of_list
     |> ReasonReact.array}
  </Map>;
};

module Button = {
  [@react.component]
  let make = (~onClick, ~color) =>
    <button onClick style={ReactDOMRe.Style.make(~color, ())} />;
};

module DangerButton = {
  let make = Button.make;
  let makeProps = Button.makeProps(~color="red");
};
