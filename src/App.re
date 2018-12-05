type state = {
  input: string,
  isLoading: bool,
};

type action =
  | UpdateInput(string)
  | Search;

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => {input: "", isLoading: false},
  reducer: (action, state) =>
    switch (action) {
    | UpdateInput(newInput) =>
      ReasonReact.Update({...state, input: newInput})
    | Search =>
    ReasonReact.UpdateWithSideEffects(
      {...state, isLoading: true},
      (
        self => {
          let value = self.state.input;
          ();
        }
      ),
    )
  },
  render: self =>
    <>
      <>
        <form onSubmit={
          ev => {
            ReactEvent.Form.preventDefault(ev);
            self.send(Search);
          }>
          <label htmlFor="search"> {ReasonReact.string("Search")} </label>
          <input
            id="search"
            name="search"
            value={self.state.input}
            onChange={
              ev => {
                let value = ReactEvent.Form.target(ev)##value;
                self.send(UpdateInput(value));
              }
            }
          />
          <button type_="submit">
            {ReasonReact.string("Submit Search")}
          </button>
        </form>
        <>
          {
            self.state.isLoading ?
              ReasonReact.string("Loading...") : ReasonReact.null
          }
        </>
      </>
      <Card
        href="http://example.com"
        name="Example.com"
        description="Link to Example.com"
      />
    </>,
};