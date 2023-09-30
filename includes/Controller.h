#ifndef CONTROLLER_H
# define CONTROLLER_H

# include <Model.h>
# include <View.h>

class Controller
{
	public:
		Controller(Model &model, View, &view);
		~Controller(void);

	private:
		Model _model;
		View _view;
	
};


#endif