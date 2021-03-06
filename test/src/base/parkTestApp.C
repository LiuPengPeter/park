//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "parkTestApp.h"
#include "parkApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
parkTestApp::validParams()
{
  InputParameters params = parkApp::validParams();
  return params;
}

parkTestApp::parkTestApp(InputParameters parameters) : MooseApp(parameters)
{
  parkTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

parkTestApp::~parkTestApp() {}

void
parkTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  parkApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"parkTestApp"});
    Registry::registerActionsTo(af, {"parkTestApp"});
  }
}

void
parkTestApp::registerApps()
{
  registerApp(parkApp);
  registerApp(parkTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
parkTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  parkTestApp::registerAll(f, af, s);
}
extern "C" void
parkTestApp__registerApps()
{
  parkTestApp::registerApps();
}
