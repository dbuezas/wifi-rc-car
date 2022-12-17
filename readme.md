# Wifi RC-Car

Uses a d1 mini with a wemos motor shield on top (HR8833 Motor Shield v1.0.0).

<img width="648" alt="image" src="https://user-images.githubusercontent.com/777196/208253315-7bae8e05-2a8d-4ae6-a43c-3bd842519791.png">


- No JS libraries
- Web side in typescript
- Communication via WebSockets
- Fully asynchronous and fully optimized
- Plays ringtones with the motor
- Multiple joystick modes
- Web content is gzipped (~4kb)

# Run

- Install platformio
- `cd web && npm install`
- Connect to serial and upload through platformio
- Connect to "Week's Amazing Car" with the phone
- Navigate to 8.8.4.4

To upload via ota, uncomment this from platformio.ini

```ini
upload_protocol = espota
upload_port = 8.8.4.4
```

# Develop web side

`cd web && npm start`

David Buezas
