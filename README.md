# Controle de Presença de Alunos - IoT

Sistema de controle de presença utilizando ESP32, Node-RED e MySQL, desenvolvido para a disciplina [nome da disciplina] - FATEC Sorocaba.

**Autor:** Rafaela Mansano

## Arquitetura

ESP32 (Wokwi) → HTTP (via túnel) → Node-RED → MySQL → Dashboard

## Tecnologias

- ESP32 (simulado via Wokwi)
- PlatformIO
- Node-RED + Node-RED Dashboard
- MySQL (XAMPP)
- Cloudflare Tunnel (para expor o Node-RED local)

## Estrutura do repositório

- `esp32/` — código-fonte do firmware (PlatformIO)
- `node-red/flow.json` — fluxo do Node-RED (importar via Menu > Import)
- `database/schema.sql` — script de criação do banco de dados
- `docs/screenshots/` — capturas de tela do sistema em funcionamento

## Como rodar o projeto

1. Importar `database/schema.sql` no MySQL
2. Instalar o Node-RED e os nós `node-red-node-mysql` e `node-red-dashboard`
3. Importar `node-red/flow.json` no Node-RED
4. Configurar a credencial do MySQL nos nós de banco
5. Abrir o projeto `esp32/` no VSCode com PlatformIO + extensão Wokwi
6. Ajustar a URL do servidor no `main.cpp`
7. Rodar a simulação com `Wokwi: Start Simulator`

## Funcionalidades

- Registro de presença via RA do aluno
- Validação de aluno cadastrado
- Dashboard com estatísticas em tempo real
- Notificações de sucesso/erro
- Gráfico de frequência por aluno