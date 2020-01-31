#include "People.h"

People::People(string fn, string ln):_firstName(fn),_lastName(ln)
{
	_email = fn + "." + ln + "@fake.itfwf.com";
}
