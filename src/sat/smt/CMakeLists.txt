z3_add_component(sat_smt
  SOURCES
    atom2bool_var.cpp
    ba_internalize.cpp
    ba_solver.cpp
    xor_solver.cpp
    euf_ackerman.cpp
    euf_internalize.cpp
    euf_model.cpp
    euf_proof.cpp
    euf_solver.cpp
  COMPONENT_DEPENDENCIES
    sat
    ast
    euf
    smt_params
)

