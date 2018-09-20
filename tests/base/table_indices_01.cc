// ---------------------------------------------------------------------
//
// Copyright (C) 2006 - 2017 by the deal.II authors
//
// This file is part of the deal.II library.
//
// The deal.II library is free software; you can use it, redistribute
// it, and/or modify it under the terms of the GNU Lesser General
// Public License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// The full text of the license can be found in the file LICENSE.md at
// the top level directory of deal.II.
//
// ---------------------------------------------------------------------


// check TableIndices in various ways

#include <deal.II/base/tensor.h>

#include <deal.II/lac/vector.h>

#include "../tests.h"

int
main()
{
  initlog();
  deallog << std::setprecision(3);

  const TableIndices<2> t1(84, 42);
  TableIndices<2>       t2;
  t2[0] = 84;
  t2[1] = 42;

  AssertThrow(t1 == t2, ExcInternalError());
  AssertThrow(t1[0] == t2[0], ExcInternalError());
  AssertThrow(t1[1] == t2[1], ExcInternalError());

  AssertThrow(!(t1 != t2), ExcInternalError());

  t2.sort();
  AssertThrow(t1 != t2, ExcInternalError());
  AssertThrow(t1[0] == t2[1], ExcInternalError());
  AssertThrow(t1[1] == t2[0], ExcInternalError());

  deallog << "OK" << std::endl;
}
