// ---------------------------------------------------------------------
//
// Copyright (C) 2002 - 2015 by the deal.II authors
//
// This file is part of the deal.II library.
//
// The deal.II library is free software; you can use it, redistribute
// it, and/or modify it under the terms of the GNU Lesser General
// Public License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// The full text of the license can be found in the file LICENSE at
// the top level of the deal.II distribution.
//
// ---------------------------------------------------------------------



// testing reading a parameter that doesn't conform to its specs. this
// incidentally also uncovered a bug in Patterns::Integer::match

#include "../tests.h"
#include <deal.II/base/logstream.h>
#include <deal.II/base/parameter_handler.h>
#include <fstream>

void check (const char *p)
{
  ParameterHandler prm;
  prm.declare_entry ("test_1", "3", Patterns::Integer());

  std::ifstream in(p);
  const bool result = prm.read_input (in);

  deallog << result << std::endl;
  deallog << "test_1=" << prm.get ("test_1") << std::endl;
}


int main ()
{
  std::ofstream logfile("output");
  deallog.attach(logfile);
  deallog.threshold_double(1.e-10);

  check (SOURCE_DIR "/prm/parameter_handler_10.prm");

  return 0;
}