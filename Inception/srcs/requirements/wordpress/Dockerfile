FROM debian:buster

RUN apt-get update
RUN apt-get -y upgrade
RUN apt-get install -y php-fpm php-mysql php-mbstring php-gd php-xml wget vim
RUN apt-get install -y redis-server php-redis
EXPOSE 9000
COPY ./conf/ /var/www/
RUN chmod +x /var/www/wordpress_php.sh
ENTRYPOINT [ "/var/www/wordpress_php.sh" ]
CMD [ "/usr/sbin/php-fpm7.3", "--nodaemonize" ]