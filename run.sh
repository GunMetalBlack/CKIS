mkdir output
g++ -c ckis.cpp -Ideps/SFML-2.6.0-linux-gcc-64-bit/SFML-2.6.0/include -o output/ckis.o  && \
g++ -c entity.cpp -Ideps/SFML-2.6.0-linux-gcc-64-bit/SFML-2.6.0/include -o output/entity.o  && \
g++ -c SpriteManager.cpp -Ideps/SFML-2.6.0-linux-gcc-64-bit/SFML-2.6.0/include -o output/SpriteManager.o  && \
g++ output/ckis.o output/SpriteManager.o output/entity.o -o output/sfml-app -Ldeps/SFML-2.6.0-linux-gcc-64-bit/SFML-2.6.0/lib -lsfml-graphics -lsfml-window -lsfml-system  && \
export LD_LIBRARY_PATH=deps/SFML-2.6.0-linux-gcc-64-bit/SFML-2.6.0/lib && ./output/sfml-app
