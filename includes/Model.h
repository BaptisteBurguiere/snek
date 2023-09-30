#ifndef MODEL_H
# define MODEL_H

# include <Map.h>
# include <Snek.h>
# include <cstdlib>

class Model
{
	public:
		Model(void);
		Model(const unsigned int size);
		~Model(void);

		void updateSnek(char dir);
		int updateMap(void);

	private:
		const unsigned int _size;
		Map _map;
		Snek _snek;
		
		void generateApple(void);
	
};

#endif