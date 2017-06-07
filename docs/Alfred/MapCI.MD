Create:

- `MapCI		initMapCI(int size, int nof)`
- `MapCI		*newMapCI(int size, int nof)`

Method:

- `MapCI	*set(MapCI *this, char *key, int data)`
- `int		get(MapCI *this, char *key)`
- `int		len(MapCI *this)`
- `int		end(MapCI *this)`
- `bool		exist(MapCI *this, char *key)`
- `char		at(MapCI *this, int pos);`

Example:
```
#include "MapCI.h";

void		mapCI_sample()
{
  MapCI		*map;

  map = newMapCI(100, -1);

  map->set(map, "toto", 1)

  printf("Test: %d\n", get(map, "toto"));
 }
```
