window.addEventListener('load', function () {
    //切换栏
    const open = document.getElementById('open');
    const close = document.getElementById("close");
    const container = document.querySelector(".container");

    open.addEventListener('click', () => container.classList.add('show-nav'));
    close.addEventListener('click', () => container.classList.remove('show-nav'));

    let part = container.children;//索引从一开始
    let li = document.querySelectorAll('nav>ul>li');
    let id = 0;
    for (let i = 0; i < li.length; i++) {
        li[i].addEventListener('click', function () {
            for (let index = 1; index < part.length; index++) {
                part[index].classList.add('hidden');
            }
            id = parseInt(this.textContent.charAt(this.textContent.length - 1));
            part[id].classList.remove('hidden');
            container.classList.remove('show-nav')
        });
    }


    //轮播图
    const sliderContainer = document.querySelector('.part2')
    const slideRight = document.querySelector('.right-slide')
    const slideLeft = document.querySelector('.left-slide')
    const upButton = document.querySelector('.up-button')
    const downButton = document.querySelector('.down-button')
    const slidesLength = slideRight.querySelectorAll('div').length;
    // 初始化设置0
    let activeSlideIndex = 0
    slideLeft.style.top = `-${(slidesLength - 1) * 100}vh`
    upButton.addEventListener('click', () => changeSlide('up'));
    downButton.addEventListener('click', () => changeSlide('down'));
    const changeSlide = (direction) => {
        const slidesHeight = sliderContainer.clientHeight
        if (direction === 'up') {
            activeSlideIndex++;
            if (activeSlideIndex > slidesLength - 1) {
                activeSlideIndex = 0;
            }
        } else if (direction === 'down') {
            activeSlideIndex--;
            if (activeSlideIndex < 0) {
                activeSlideIndex = slidesLength - 1;
            }
        }
        slideRight.style.transform = `translateY(-${activeSlideIndex * slidesHeight}px)`;
        slideLeft.style.transform = `translateY(${activeSlideIndex * slidesHeight}px)`;
    }


    //模拟键盘
    // 或者键盘上你所对应的按键
    document.addEventListener("keydown",event=>{
        // 通过接收一个Unicode来返回一个字符串
        let keyPassed = String.fromCharCode(event.keyCode)
        // 然后获得指定的element
        const keyElement = document.getElementById(keyPassed);
        // 然后使它动画
        keyElement.classList.add("hit");
        // 监听动画是否完成，完成的话移除hit
        keyElement.addEventListener("animationend",()=>{
            keyElement.classList.remove("hit");
        });
        const heightlightedKey = document.querySelector(".selected");
        if(keyPassed === heightlightedKey.innerHTML){
            heightlightedKey.classList.remove("selected");
            targetRandomKey();
        }
    })
    // 创建所有的字母
    const keys = [..."ABCDEFGHIJKLMNOPQRSTUVWXYZ"];
    // 随机获取0-24间的整数
    function getRandomNumber(min,max){
        min = Math.ceil(min);
        max = Math.floor(max);
        return Math.floor(Math.random() * (max + 1));
    }
    // 随机获取一个字母
    function getRandomKey(){
        return keys[getRandomNumber(0,keys.length - 1)];
    }
    function targetRandomKey(){
        const key = document.getElementById(getRandomKey());
        key.classList.add("selected");
    }
    targetRandomKey();

});