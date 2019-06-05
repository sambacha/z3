/*++
  Copyright (c) 2017 Microsoft Corporation

  Module Name:

  <name>

  Abstract:

  <abstract>

  Author:
  Nikolaj Bjorner (nbjorner)
  Lev Nachmanson (levnach)

  Revision History:


  --*/
#include "math/lp/nla_solver.h"
#include <map>
#include "math/lp/monomial.h"
#include "math/lp/lp_utils.h"
#include "math/lp/var_eqs.h"
#include "math/lp/factorization.h"
#include "math/lp/nla_solver.h"
namespace nla {

// returns the monomial index
void solver::add_monomial(lpvar v, unsigned sz, lpvar const* vs) {
    m_core->add(v, sz, vs);
}

bool solver::is_monomial_var(lpvar v) const {
    return m_core->is_monomial_var(v);
}

bool solver::need_check() { return true; }

lbool solver::check(vector<lemma>& l) {
    return m_core->check(l);
}

void solver::push(){
    m_core->push();
}

void solver::pop(unsigned n) {
    m_core->pop(n);
}

    std::ostream& solver::display(std::ostream& out) {
        return m_core->print_monomials(out);
    }

        
solver::solver(lp::lar_solver& s) {
    m_core = alloc(core, s);
}

solver::~solver() {
    dealloc(m_core);
}
lp::impq solver::get_upper_bound(lpvar j) const {
    SASSERT(is_monomial_var(j) && m_core->monomial_has_upper_bound(j));    
    return m_core->get_upper_bound_of_monomial(j);
}

lp::impq solver::get_lower_bound(lpvar j) const {
    SASSERT(is_monomial_var(j) && m_core->monomial_has_lower_bound(j));
    return m_core->get_lower_bound_of_monomial(j);
}

bool solver::monomial_has_lower_bound(lpvar j) const {
    return m_core->monomial_has_lower_bound(j);
}
bool solver::monomial_has_upper_bound(lpvar j) const {
    return m_core->monomial_has_upper_bound(j);
}

}
