import { Injectable } from '@angular/core';

@Injectable()
export class ProductService {

  constructor() { }

  private products:Product[] = [
    new Product(1,"第一个商品",2.99,4.5,"第二个商品的描述",["硬设"]),
    new Product(2,"第二个商品",2.99,4.5,"第二个商品的描述",["硬件设备"]),
    new Product(3,"第三个商品",3.99,2.5,"第三个商品的描述",["电子产品",]),
    new Product(4,"第四个商品",4.99,1.5,"第四个商品的描述",["图书"]),
    new Product(5,"第五个商品",5.99,0.5,"第五个商品的描述",["电子产品","硬件设备"]),
    new Product(6,"第六个商品",6.99,5.0,"第六个商品的描述",["电子产品","硬件设备"]),
  ];

  private comments: Comment[] = [
    new Comment(1, 1, '2017-02-02 22:22:22', "张三", 3, "东西不错"),
    new Comment(2, 1, '2017-02-02 21:22:22',  "张八", 4, "东西不错"),
    new Comment(3, 3, '2017-02-02 2:22:22', "水来", 2, "东西还不错"),
    new Comment(4, 2, '2017-02-01 22:22:22', "无三", 5, "东西好"),
  ]

  getProducts(): Product[] {
    return this.products;
  }

  getProduct(id: number): Product {
    return this.products.find((product) => product.id == id);
  }

  getCommentsForProductId(id: number): Comment[] {
    return this.comments.filter((comment: Comment) => comment.productId == id);
  }

}

export class Product {

  constructor(
    public id: number,
    public title: string,
    public price: number,
    public rating: number,
    public desc: string,
    public categories: Array<string>
  ) {

  }
}

export class Comment {
  constructor(public id: number,
              public productId: number,
              public timestamp: string,
              public user: string,
              public rating: number,
              public content: string
  ){

  }
}
