#ifndef CONTROLLER_H
# define CONTROLLER_H

# include <Model.h>
# include <View.h>
# include <cstdlib>
# include <time.h>

class Controller
{
	public:
		Controller(Model &model, View &view);
		~Controller(void);

		void updateView(void);
		int updateModel(char dir = ' ');

	private:
		Model _model;
		View _view;
	
};


#endif