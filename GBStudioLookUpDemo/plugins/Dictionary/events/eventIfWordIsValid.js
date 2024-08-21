const id = "PT_EVENT_IF_WORD_IS_VALID";
const groups = ["EVENT_GROUP_CONTROL_FLOW", "Dictionary"];
const name = "If is valid word";

const fields = [
  {
    key: "true",
    label: "True",
    type: "events",
  },
  {
    key: "__collapseElse",
    label: "Else",
    type: "collapsable",
    defaultValue: true,
    conditions: [
      {
        key: "__disableElse",
        ne: true,
      },
    ],
  },
  {
    key: "false",
    label: "False",
    conditions: [
      {
        key: "__collapseElse",
        ne: true,
      },
      {
        key: "__disableElse",
        ne: true,
      },
    ],
    type: "events",
  },
];

const compile = (input, helpers) => {
  const {
    appendRaw,
    getNextLabel,
    _ifConst,
    _compilePath,
    _jump,
    _label,
    _addNL,
  } = helpers;

  const truePath = input.true;
  const falsePath = input.__disableElse ? [] : input.false;
  const trueLabel = getNextLabel();
  const endLabel = getNextLabel();

  appendRaw(`; Is valid word?
    VM_PUSH_CONST 0
    
    VM_CALL_NATIVE b_isThisAWord, _isThisAWord
  `);

  _ifConst(".EQ", ".ARG0", 1, trueLabel, 0);
  _compilePath(falsePath);
  _jump(endLabel);
  _label(trueLabel);
  _compilePath(truePath);
  _label(endLabel);
  _addNL();

  appendRaw(`
    VM_POP 1
  `);
};

module.exports = {
  id,
  name,
  groups,
  fields,
  compile,
};
