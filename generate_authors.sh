#!/bin/bash

{
	cat <<-'EOH'
# This file lists all individuals having contributed content to the repository.
# For how it is generated, see 'generate_authors.sh'
EOH
echo
git log --format='%aN <%aE>' | LC_ALL=C.UTF-8 sort -uf
} > AUTHORS
