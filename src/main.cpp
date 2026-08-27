#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* serverUrl = "https://streets-mardi-accounting-advocate.trycloudflare.com/presenca";
String raBuffer = "";

void enviarPresenca(String ra);

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Conectando ao WiFi...");

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi conectado!");
  Serial.println("Digite o RA do aluno e pressione Enter:");
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();

    if (c == '\n' || c == '\r') {
      if (raBuffer.length() > 0) {
        Serial.println();
        enviarPresenca(raBuffer);
        raBuffer = "";
      }
    } else {
      raBuffer += c;
      Serial.print(c);
    }
  }
}

void enviarPresenca(String ra) {
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClientSecure client;
    client.setInsecure();

    HTTPClient http;
    http.begin(client, serverUrl);
    http.addHeader("Content-Type", "application/json");

    JsonDocument doc;
    doc["ra"] = ra;
    String body;
    serializeJson(doc, body);

    Serial.println("Enviando presenca...");
    int httpCode = http.POST(body);

    if (httpCode > 0) {
      String resposta = http.getString();
      Serial.println("Resposta (" + String(httpCode) + "): " + resposta);
    } else {
      Serial.println("Erro na requisicao: " + String(httpCode));
    }
    http.end();
  } else {
    Serial.println("WiFi desconectado!");
  }
}