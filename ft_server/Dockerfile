# Откуда
FROM debian:buster

# Установка компонентов
RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install -y nginx
RUN apt-get install -y wget
RUN apt-get install -y mariadb-server
RUN apt-get install openssl
RUN apt-get -y install php7.3 php-mysql php-fpm php-pdo php-gd php-cli php-mbstring

WORKDIR /var/www/html/

#phpMyAdmin
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-english.tar.gz
RUN tar -xf phpMyAdmin-5.0.1-english.tar.gz && rm -rf phpMyAdmin-5.0.1-english.tar.gz
RUN mv phpMyAdmin-5.0.1-english phpmyadmin
COPY ./srcs/config.inc.php phpmyadmin

#WordPress
RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvzf latest.tar.gz && rm -rf latest.tar.gz
COPY ./srcs/wp-config.php wordpress

#Ssl
RUN openssl req -new -x509 -nodes -sha256 -days 365 \
    -newkey rsa:2048 \
    -keyout /etc/ssl/nginx-selfsigned.key -out /etc/ssl/nginx-selfsigned.crt \
    -subj '/C=RU/L=Moscow/CN=localhost'

COPY ./srcs/nginx.conf /etc/nginx/sites-enabled

#Саздаем папки для скриптов и конфигов
RUN mkdir /sh/ /conf/
RUN chmod -R 755 /sh/

COPY ./srcs/start.sh /sh/
COPY ./srcs/index_on.sh /sh/
COPY ./srcs/index_off.sh /sh/

COPY ./srcs/nginx_off.conf /conf/

RUN rm index.nginx-debian.html

EXPOSE 80 443

CMD bash /sh/start.sh
