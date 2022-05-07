flags = -pedantic-errors -std=c++11

pokemon_gen_prep.o: pokemon_gen_prep.cpp pokemon_struct.h 
	g++ $(flags) -c $<

pokemon_list_input.o: pokemon_list_input.cpp pokemon_struct.h
	g++ $(flags) -c $<

print_battle.o: print_battle.cpp pokemon_struct.h
	g++ $(flags) -c $<

pokemon_main.o: pokemon_main.cpp pokemon_list_input.h pokemon_struct.h print_battle.h pokemon_gen_prep.h
	g++ $(flags) -c $<

game: pokemon_gen_prep.o pokemon_list_input.o print_battle.o pokemon_main.o
	g++ $(flags) $^ -o $@

clean:
	rm -rf *.o game

tar:
	tar -czvf game.tgz *.cpp *.h
