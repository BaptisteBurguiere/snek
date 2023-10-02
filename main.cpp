#include <Model.h>
#include <View.h>
#include <Controller.h>
#include <iostream>
#include <unistd.h>

int main(void)
{
	Model model = Model();
	View view = View();
	Controller controller = Controller(model, view);
	controller.updateView();
	for (int i = 0; i < 20; ++i)
	{
		usleep(100000);
		if (controller.updateModel() != -1)
			return 0;
		controller.updateView();
	}
	return 0;
}