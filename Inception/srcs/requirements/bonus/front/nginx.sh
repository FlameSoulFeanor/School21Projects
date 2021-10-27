#!/usr/bin/env bash
openssl req -x509 -nodes -days 365 -subj "/C=RU/ST=Russia/L=Moscow/O=School_21/OU=42moscow/CN=hfunctio" -newkey rsa:2048 -keyout /etc/nginx/private.key -out /etc/nginx/certificate.crt;
exec "$@"