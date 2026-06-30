#! /bin/sh

read -p "Problem Number: " num
read -p "Problem Letter: " letter
read -p "Programming language (extension): " lang


template="./TEMPLATES/main.${lang}"

if [[ ! -f "$template" ]]; then
  echo "Template for ${lang} does not exist!"
  echo "Available templates: "
  tput bold
  ls ./TEMPLATES/
  tput sgr0
  exit
fi

dir="./${num}/${letter^^}"

mkdir -p $dir
cp $template $dir

# Create a new branch 

git checkout -b "${num}/${letter^^}"


tput bold
echo "cd" $dir
tput sgr0

wl-copy "cd $dir"
