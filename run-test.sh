# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run-test.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 10:51:12 by susami            #+#    #+#              #
#    Updated: 2022/04/07 22:18:31 by yahokari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

git_clone_if_none()
{
	if [ ! -d $LOCALREPO ]
	then
		git clone $REPOSRC $LOCALREPO
	fi
}

INITIAL_DIR=$(pwd)
echo "Tests by 'libft-unit-test'"
make bonus
cd ..
REPOSRC=https://github.com/alelievr/libft-unit-test.git
LOCALREPO=libft-unit-test
git_clone_if_none
cd $LOCALREPO
make f
cd ..
cd $INITIAL_DIR
echo $(pwd)
echo "Tests by 'libftTester'"
REPOSRC=https://github.com/Tripouille/libftTester.git
LOCALREPO=libftTester
git_clone_if_none
cd $LOCALREPO
make
cd $INITIAL_DIR
rm -rf $LOCALREPO
echo $(pwd)
echo "Tests by 'Usami'sTester'"
REPOSRC=https://github.com/usatie/libft-tester-tokyo
LOCALREPO=usaTester
git_clone_if_none
cd $LOCALREPO
make
cd $INITIAL_DIR
rm -rf $LOCALREPO
make fclean
