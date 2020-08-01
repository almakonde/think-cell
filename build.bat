mkdir build
pushd build
	cmake ..
	cmake --build . --config Release
	ctest -c Release --output-on-failure
popd