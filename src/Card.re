let component = ReasonReact.statelessComponent("Card");

let make = (~name, ~description, ~href, _children) => {
    ...component,
    render: _self => 
    <div>
        {ReasonReact.string("Text")}
    </div>
};