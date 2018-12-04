let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
  render: _self =>
    <Card
      href="http://example.com"
      name="Example.com"
      description="Link to Example.com"
    />,
};