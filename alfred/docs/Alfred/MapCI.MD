Create:

- `MapCI		init_map_ci(int size, int nof)`
- `MapCI		*new_map_ci(int size, int nof)`

Method:

- `MapCI	*set(MapCI *this, char *key, int data)`
- `int		get(MapCI *this, char *key)`
- `int		len(MapCI *this)`
- `int		end(MapCI *this)`
- `bool		exist(MapCI *this, char *key)`
- `char		at(MapCI *this, int pos);`
- `void		start_loop(MapCI *this);`
- `PAIR_CI	*loop(MapCI *this);`
- `void		*print(MapCI *this, void (*_func)(PAIR_CI *pair));`

Example:
```
#include "MapCI.h";

void		mapCI_sample()
{
  MapCI		*map;
  PAIR_CI	*pair;
  
  map = new_map_ci(100, -1);

  map->set(map, "toto", 1);
  map->set(map, "salut", 2);;

  printf("Test: %d\n", map->get(map, "toto"));
  
  map->start_loop(map);
  while ((pair = map->loop(map)) NOT NULL)
    printf("key: %s data: %d\n", pair->key, pair->data); 
 }
```
