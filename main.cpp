#include <Model.h>
#include <View.h>
#include <Controller.h>
#include <iostream>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	Model model = Model(30);
	View view = View(30);
	Controller controller(model, view);
	controller.updateView();
	while(true)
	{
		usleep(50000);
		if (controller.updateModel() != -1)
		{
			controller.exit();
			// sleep(2);
			return 0;
		}
		controller.updateView();
	}
	return 0;
}