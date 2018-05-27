[@bs.deriving abstract]
type zoomableGroupProps = {
  disablePanning: bool,
  center: (int, int)
}

module ZoomableGroup = {
  [@bs.module "react-simple-maps"] 
  external externalCompoosableMap: ReasonReact.reactClass = "ZoomableGroup";

  let make = (~disablePanning, ~center, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=externalCompoosableMap,
      ~props=zoomableGroupProps(
        ~disablePanning,
        ~center),
      children
    );
};


[@bs.deriving abstract]
type geographiesProps = {
  geography: string
}
module Geographies = {
  [@bs.module "react-simple-maps"] 
  external externalCompoosableMap: ReasonReact.reactClass = "Geographies";

  let make = (~geography, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=externalCompoosableMap,
      ~props=geographiesProps(~geography),
      children
    );
};


[@bs.deriving abstract]
type geographyProps = {
  geography: string,
  projection: string
}
module Geography = {
  [@bs.module "react-simple-maps"] 
  external externalCompoosableMap: ReasonReact.reactClass = "Geographie";

  let make = (~geography, ~projection, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=externalCompoosableMap,
      ~props=geographyProps(
        ~geography,
        ~projection
      ),
      children
    );
};


module ComposableMap = {
  [@bs.module "react-simple-maps"] 
  external externalCompoosableMap: ReasonReact.reactClass = "ComposableMap";

  let make = children =>
    ReasonReact.wrapJsForReason(
      ~reactClass=externalCompoosableMap,
      ~props=Js.Obj.empty(),
      children,
    );
};

ReactDOMRe.renderToElementWithId(
  <ComposableMap>
   <ZoomableGroup center=(0, 20) disablePanning=true>
     <Geographies geography="https://raw.githubusercontent.com/zcreativelabs/react-simple-maps/master/examples/basic-map/static/world-50m.json">

     ((geographies, projection) => ReasonReact.array(geographies |> Array.mapi((geography, i) => (
           <Geography geography="" key=("geography-"++i) projection="" />
     ))))
     </Geographies>
   </ZoomableGroup>
 </ComposableMap>,
 "index1");


