#pragma once

#include <pgmspace.h>

static const char CA_CERT[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDzzCCAregAwIBAgIUAoxVAYGMOZjnOmWvIbnF1gZN5v8wDQYJKoZIhvcNAQEL
fdasfasdfsadfasdfasdfdasfafdafdafdafdsafdsafdsafdas
MTIxMzEwMDEyM1owdzELMAkGA1UEBhMCQ1oxFzAVBgNVBAgMDkN6ZWNoIFJlcHVi
bGljMQ8wDQYDVQQHDAZQcmFndWUxHjAcBgNVBAoMFVByb3RlY2NNUVRUIEF1dGhv
fasdfsafasdafsdafasfdasfafdasfdasfdafdfasdfasfdsafdsafasdfsda
A1wHYcEsAS909GXvTISn3ayCoe/7i9P2sdEwIzCfRcpDfyxl1nx0swgqR/gFrwTQ
dri1I7A0PTQBRoUhSVugyc9U4g==
-----END CERTIFICATE-----
)EOF";

static const char CLIENT_CERT[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDYzCCAksCFDDIsNyR1UChHfq4GdGscuqF9YsHMA0GCSqGSIb3DQEBCwUAMHcx
fdsafdsafsadfdasgqgjifjkafjeopwjfdajfdjajfdkajfkjsdaklckjdskajdf
VRVfdgWqbCOlrQr2noX90E8kmwjZiVa/CD+PO36FlouWVtO1HoBf7nADsHvFirGx
x8VtmTFMplr/n87w/Vb1zZI0Dg9XSjM1hMd4BJoSe8/reJ3Sf25rtr9uRyWpXGAP
fsdafsdadfadfasdghasgjkqvjkavhiuhvewfuufegugfeuguewqguzfgequfdfa
5sxzDuyE0g==
-----END CERTIFICATE-----
)EOF";


static const char CLIENT_KEY[] PROGMEM = R"EOF(
-----BEGIN RSA PRIVATE KEY-----
MIIEpQIBAAKCAQEApltVFV92BapsI6WtCvaehf3QTySbCNmJVr8IP487foWWi5ZW
fasdhfiweqhfiodhasuifhuosiahfuhdsufhdsauiohfuidsahfousdhaiufhaff
fdsafdsafasdhufqgpioashdfpuhasdpífjsdipahfeíuhwuffhsdahfoashiofh
fsdauhfuqwhguihsdaupfhsdauhfiuhigufsdhaupfghasupghasduhfuidsahff
Zu3t9Gk5kIVDcaPB1cfzdwG/AmeJqgFgdFqd8DjGQiIaPQzb63MCc0U=
-----END RSA PRIVATE KEY-----
)EOF";