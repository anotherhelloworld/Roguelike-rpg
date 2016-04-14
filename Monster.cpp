#include "Inspector.h"

void Monster::Move(Map& map) {	
	Inspector inspector = Inspector::GetInstance();
	std::vector <intVector2> path;	
	intVector2 target = intVector2(inspector.GetKnight().GetPos().first, inspector.GetKnight().GetPos().second);
	intVector2 prev = pos;
	if (FindPath(pos, inspector.GetKnight().GetPos(), map, path)) {		
		map.objects[path[1].first][path[1].second]->Collide(this);		
		Inspector::GetInstance().SwapObjects(prev, pos);			
	}
	else {
		intVector2 tmp(rand() % 3 + (-1), rand() % 3 + (-1));		
		map.objects[pos.first + tmp.first][pos.second + tmp.second]->Collide(this);		
		Inspector::GetInstance().SwapObjects(prev, pos);		
	}
	map.map[prev.first][prev.second] = pass;
	map.map[pos.first][pos.second] = Symbol();
	return;
}

void Monster::CollideWith(Pass* pass) {
	intVector2 tmp = this->pos;
	this->pos = pass->GetPos();
	pass->SetPos(tmp);
	return;
}

void Monster::CollideWith(Knight* obj) {
	obj->TakeDamage(damage);
};

bool Monster::FindPath(intVector2 a, intVector2 b, Map& map, std::vector <intVector2>& path) const {
	const int WALL = -1;
	const int PASS = -2;

	std::vector <std::vector <int>> grid(map.width, std::vector <int>(map.height));
	for (int i = 0; i < map.map.size(); i++) {
		for (int j = 0; j < map.map.size(); j++) {
			if ((i == a.first) && (j == a.second)) {
				grid[j][i] = PASS;
				continue;
			}
			if (map.map[i][j] == wall) {
				grid[j][i] = WALL;				
			}
			else if (map.map[i][j] == pass) {
				grid[j][i] = PASS;
			}
			else if (map.map[i][j] == knightSymbol) {
				grid[j][i] = PASS;
			}
			else if (map.map[i][j] == zombieSymbol) {
				grid[j][i] = WALL;
			}
			else if (map.map[i][j] == dragonSymbol) {
				grid[j][i] = WALL;
			}
			else if (map.map[i][j] == princessSymbol) {
				grid[j][i] = WALL;
			}
			else if (map.map[i][j] == medkit) {
				grid[j][i] = PASS;
			}
			else if (map.map[i][j] == wizardSymbol) {
				grid[j][i] = WALL;
			}		
			else if (map.map[i][j] == rightFireball) {
				grid[j][i] = PASS;
			}
			else if (map.map[i][j] == leftFireball) {
				grid[j][i] = PASS;
			}
			else if (map.map[i][j] == upFireball) {
				grid[j][i] = PASS;
			}
			else if (map.map[i][j] == downFireball) {
				grid[j][i] = PASS;
			}
			else if (map.map[i][j] == nest) {
				grid[j][i] = WALL;
			}
			else if (map.map[i][j] == graveyard) {
				grid[j][i] = WALL;
			}
		}
	}

	path.resize(map.width * map.height);
	int len;

	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	int d, x, y, k;
	bool stop;

	if (grid[a.second][a.first] == WALL || grid[b.second][b.first] == WALL) {
		return false;
	}

	d = 0;
	grid[a.second][a.first] = 0;
	do {
		stop = true;
		for (y = 0; y < map.height; ++y)
			for (x = 0; x < map.width; ++x)
				if (grid[y][x] == d) {
					for (k = 0; k < 4; ++k) {
						int iy = y + dy[k], ix = x + dx[k];
						if (iy >= 0 && iy < map.height && ix >= 0 && ix < map.width &&
							grid[iy][ix] == PASS) {
							stop = false;
							grid[iy][ix] = d + 1;
						}
					}
				}
		d++;
	} while (!stop && grid[b.second][b.first] == PASS);

	if (grid[b.second][b.first] == PASS) {
		return false;
	}


	len = grid[b.second][b.first];
	x = b.first;
	y = b.second;
	d = len;

	while (d > 0) {
		path[d] = intVector2(x, y);
		d--;
		for (k = 0; k < 4; ++k) {
			int iy = y + dy[k], ix = x + dx[k];
			if (iy >= 0 && iy < map.height && ix >= 0 && ix < map.width &&
				grid[iy][ix] == d) {
				x = x + dx[k];
				y = y + dy[k];
				break;
			}
		}
	}

	path[0] = intVector2(b.first, b.second);
	return true;
}

bool Monster::FireballCheck(char symbol) {
	if (symbol == rightFireball || symbol == leftFireball ||
		symbol == upFireball || symbol == downFireball) {
		return true;
	}
	return false;
}