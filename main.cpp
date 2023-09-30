#include <Model.h>
#include <View.h>
#include <iostream>

int main(void)
{
	Model model = Model();
	View view = View();
	view.drawMap();
	return 0;
}