FROM debian:buster

RUN apt-get update
RUN apt-get -y upgrade
RUN apt-get install -y openssl php-gd php-xml vim nginx sudo
EXPOSE 443
COPY ./conf/nginx.sh /var/www/
COPY ./conf/nginx.conf        /etc/nginx/sites-available/default
RUN chmod +x /var/www/nginx.sh
ENTRYPOINT ["/var/www/nginx.sh"]
CMD ["nginx", "-g", "daemon off;"]