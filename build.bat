mkdir build
pushd build
	cmake ..
	cmake --build . --config Debug --generator "Visual Studio 16 2019"
	ctest --build-config Debug --output-on-failure
popd