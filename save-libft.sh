cp -rf libft/srcs ../libft/.
cp -rf libft/includes ../libft/.
cp libft/Makefile ../libft/.
cd ../libft
git add .
git commit -m "update from fract-ol"
git push
cd ../fract-ol