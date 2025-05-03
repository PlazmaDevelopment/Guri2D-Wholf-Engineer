# Guri2D

Guri2D, Wholf dilinde 2D oyun geliştirme için kullanılan güçlü bir kütüphanedir.

## Özellikler

- Kanvas yönetimi
- 2D fizik sistemi
- Ses sistemi
- Kullanıcı girişi sistemi
- Olay yönetimi
- Performans optimizasyonları

## Kurulum

```wholf
fort import "Guri2D"
```

## Kullanım

### Temel Kullanım

```wholf
// Kanvas oluşturma
fegn Guri2D {
    createCanvas: (800, 600) => {
        Console.log("Kanvas oluşturuldu")
    }
}

// Kanvas yükleme
fegn Guri2D {
    loadCanvas: () => {
        Console.log("Kanvas yüklendi")
    }
}
```

### Terminal Komutları

```wholf
guri -canv create  // Yeni kanvas aç
```

```wholf
guri -canv load    // Kanvas yükle
```

### Fizik Sistemi

```wholf
// Fizik nesnesi ekle
fegn Guri2D {
    addPhysicsObject: (object) => {
        Console.log("Fizik nesnesi eklendi")
    }
}

// Fizik güncelleme
fegn Guri2D {
    updatePhysics: (deltaTime) => {
        Console.log("Fizik güncellendi")
    }
}
```

### Ses Sistemi

```wholf
// Ses ekle
fegn Guri2D {
    addSound: ("music", "music.mp3") => {
        Console.log("Ses eklendi")
    }
}

// Ses oynat
fegn Guri2D {
    playSound: ("music") => {
        Console.log("Ses oynatıldı")
    }
}
```

### Kullanıcı Girişi

```wholf
// Tuş olayları
fegn Guri2D {
    onKeyDown: (key, callback) => {
        Console.log("Tuş basıldı: " + key)
    }
}

// Fare olayları
fegn Guri2D {
    onMouseMove: (callback) => {
        Console.log("Fare hareket etti")
    }
}
```

## Lisans

MIT License
