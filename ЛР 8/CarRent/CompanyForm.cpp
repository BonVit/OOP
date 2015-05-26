#include "CompanyForm.h"

using namespace System::Windows::Forms;

void main()
{
	Application::EnableVisualStyles();

	CarRent::CompanyForm company_form;
	Application::Run(%company_form);
}