find . -type f -name '*.sh' | rev | cut -d '.' -f 2 | rev | tr -d '/'
